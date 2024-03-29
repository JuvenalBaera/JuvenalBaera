select * from usuario;
select * from contacto;
select * from credenciais;
select * from carro;

-- usuário com carro
select nome, apelido, count(*) as "# carros"
from usuario join carro 
on usuario.id = carro.usuario_id
group by usuario.id;

-- carro sem usuario
select * from carro where usuario_id is null;