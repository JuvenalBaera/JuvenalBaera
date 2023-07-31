CREATE DATABASE IF NOT EXISTS gestaoClientes;

USE gestaoClientes;

CREATE TABLE IF NOT EXISTS clientes(
    id_cliente INT NOT NULL AUTO_INCREMENT,
    nome VARCHAR(20) NOT NULL,
    sobrenome VARCHAR(20) NOT NULL,
    nascimento DATE NOT NULL,
    sexo ENUM("M", "F"),
    PRIMARY KEY(id_cliente)
);

CREATE TABLE IF NOT EXISTS enderecos(
    id_endereco INT NOT NULL AUTO_INCREMENT,
    id_cliente INT NOT NULL,
    codigo_postal VARCHAR(10),
    rua VARCHAR(255) NOT NULL,
    cidade VARCHAR(30),
    pais VARCHAR(30),
    PRIMARY KEY(id_endereco),
    FOREIGN KEY (id_cliente) REFERENCES clientes(id_cliente)
);

CREATE TABLE IF NOT EXISTS contactos(
    id_contacto INT NOT NULL PRIMARY KEY AUTO_INCREMENT,
    id_cliente INT NOT NULL,
    telefone VARCHAR(20),
    email VARCHAR(50),
    FOREIGN KEY (id_cliente) REFERENCES clientes(id_cliente)
);

CREATE TABLE IF NOT EXISTS produtos(
    id_produto INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    nome_produto VARCHAR(30),
    preco_produto DECIMAL(9, 2),
    quantidade_produto SMALLINT NOT NULL
);

CREATE TABLE IF NOT EXISTS pedidos(
    id_pedido INT NOT NULL AUTO_INCREMENT,
    id_cliente INT NOT NULL,
    id_produto INT NOT NULL,
    quantidade_pedido INT NOT NULL,
    data_pedido DATETIME,
    preco_total DECIMAL(9, 2),
    estado VARCHAR(20),
    PRIMARY KEY(id_pedido),
    FOREIGN KEY (id_cliente) REFERENCES clientes(id_cliente),
    FOREIGN KEY (id_produto) REFERENCES produtos(id_produto)
);

CREATE TABLE IF NOT EXISTS pagamentos(
    id_pagamento INT NOT NULL AUTO_INCREMENT,
    id_cliente INT NOT NULL,
    id_pedido INT NOT NULL,
    valor_pago DECIMAL(9, 2),
    tipo_pagamento ENUM("CARTÃO", "DINHEIRO"),
    PRIMARY KEY(id_pagamento),
    FOREIGN KEY (id_cliente) REFERENCES clientes(id_cliente),
    FOREIGN KEY (id_pedido) REFERENCES pedidos(id_pedido)
);
