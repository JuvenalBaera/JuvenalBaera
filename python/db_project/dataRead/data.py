import csv

def get_personal_data():
    file = open("dataRead/personal.csv", "r", encoding="UTF-8")
    next(file)
    data = []
    for row in csv.reader(file):
        data.append([row[1], row[2], row[3], row[4]])
    return data


def get_contact_data():
    file = open("dataRead/contact.csv", "r", encoding="UTF-8")
    next(file)
    data = []
    for row in csv.reader(file):
        data.append([row[1], row[2], row[3]])
    return data


def get_address_data():
    file = open("dataRead/address.csv", "r", encoding="UTF-8")
    next(file)
    data = []
    for row in csv.reader(file):
        data.append([row[1], row[2], row[3], row[4], row[5], row[6]])
    return data


def get_social_info_data():
    file = open("dataRead/social.csv", "r", encoding="UTF-8")
    next(file)
    data = []
    for row in csv.reader(file):
        data.append([row[1], row[2], row[3], row[4]])
    return data


def get_bank_data():
    file = open("dataRead/bank.csv", "r", encoding="UTF-8")
    next(file)
    data = []
    for row in csv.reader(file):
        data.append([row[1], row[2], row[3], row[4], row[5]])
    return data


def get_company_data():
    file = open("dataRead/company.csv", "r", encoding="UTF-8")
    next(file)
    data = []
    for row in csv.reader(file):
        data.append([row[1], row[2], row[3], row[4], row[5]])
    return data


def get_credential_data():
    file = open("dataRead/credential.csv", "r", encoding="UTF-8")
    next(file)
    data = []
    for row in csv.reader(file):
        data.append([row[1], row[2], row[3]])
    return data
