from dataRead import data
from database import database
from database import inputclass

personal_data = data.get_personal_data()
contact_data = data.get_contact_data()
address_data = data.get_address_data()
social_data = data.get_social_info_data()
bank_data = data.get_bank_data()
company_data = data.get_company_data()
credential_data = data.get_credential_data()

# d = inputclass.Date(19, 6, 2001)
# d.showDate()

p = inputclass.Personal("Juvenal", "Baera", "M", 29, 2, 2001)
c = inputclass.Contact(p, "juvenal@gmail.com", "123-456-7890")
c.showContac()
# p.showPerson()
# p.showDate()


# for data in personal_data:
#     database.insert_personal(data)

# for data in contact_data:
#     database.insert_contact(data)

# for data in address_data:
#     database.insert_address(data)

# for data in social_data:
#     database.insert_social_info(data)

# for data in bank_data:
#     database.insert_bank(data)

# for data in company_data:
#     database.insert_company(data)

# for data in credential_data:
#     database.insert_credential(data)