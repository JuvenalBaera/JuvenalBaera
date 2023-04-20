from dataRead import data
from database import database

personal_data = data.get_personal_data()
contact_data = data.get_contact_data()
address_data = data.get_address_data()
social_data = data.get_social_info_data()
bank_data = data.get_bank_data()
company_data = data.get_company_data()
credential_data = data.get_credential_data()

# for data in personal_data:
#     database.insert_personal(data)

# for data in contact_data:
#     database.insert_contact(data)

for data in address_data:
    # print(data)
    # break
    database.insert_address(data)

# for data in social_data:
#     database.insert_social_info(data)

# for data in bank_data:
#     database.insert_bank(data)

# for data in company_data:
#     database.insert_company(data)

# for data in credential_data:
#     database.insert_credential(data)