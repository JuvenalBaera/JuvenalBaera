CREATE DATABASE IF NOT EXISTS myproject;
USE myproject;

CREATE TABLE IF NOT EXISTS personal(
	personal_id INT AUTO_INCREMENT,
    first_name VARCHAR(30) NOT NULL,
    last_name VARCHAR(30) NOT NULL,
    gender ENUM('M', 'F') NOT NULL,
    dob DATE NOT NULL,
    PRIMARY KEY(personal_id)
);

CREATE TABLE IF NOT EXISTS contact(
	contact_id INT AUTO_INCREMENT,
    personal_id INT NOT NULL,
    email VARCHAR(60),
    phone_number VARCHAR(20),
    PRIMARY KEY(contact_id),
    FOREIGN KEY(personal_id) REFERENCES personal(personal_id)
);

CREATE TABLE IF NOT EXISTS address(
	address_id INT AUTO_INCREMENT,
    personal_id INT NOT NULL,
    country VARCHAR(50),
    city VARCHAR(50),
    postal_code VARCHAR(20),
    street_number VARCHAR(20),
    street_name VARCHAR(50),
    PRIMARY KEY (address_id),
    FOREIGN KEY(personal_id) REFERENCES personal(personal_id)
);

CREATE TABLE IF NOT EXISTS social_info(
	social_id INT AUTO_INCREMENT,
    personal_id INT NOT NULL,
    citizen_card VARCHAR(50) NOT NULL,
    ssn VARCHAR(50) NOT NULL,
    fiscal_number VARCHAR(50),
    PRIMARY KEY(social_id),
    FOREIGN KEY(personal_id) REFERENCES personal(personal_id)
);

CREATE TABLE IF NOT EXISTS bank(
	bank_id INT AUTO_INCREMENT,
    personal_id INT NOT NULL,
    credit_type VARCHAR(50) NOT NULL,
    credit_card VARCHAR(50) NOT NULL,
    iban VARCHAR(50) NOT NULL,
    validade DATE,
    PRIMARY KEY(bank_id),
    FOREIGN KEY(personal_id) REFERENCES personal(personal_id)
);

CREATE TABLE IF NOT EXISTS company(
	company_id INT AUTO_INCREMENT,
    personal_id INT NOT NULL,
    company_name VARCHAR(100) NOT NULL,
    department VARCHAR(100) NOT NULL,
    contract_code VARCHAR(15),
    hired_date DATE,
    PRIMARY KEY(company_id),
    FOREIGN KEY(personal_id) REFERENCES personal(personal_id)
);

CREATE TABLE IF NOT EXISTS credential(
	credential_id INT AUTO_INCREMENT,
    personal_id INT NOT NULL,
    username VARCHAR(50) NOT NULL UNIQUE,
    password VARCHAR(255),
    PRIMARY KEY(credential_id),
    FOREIGN KEY(personal_id) REFERENCES personal(personal_id)
);
