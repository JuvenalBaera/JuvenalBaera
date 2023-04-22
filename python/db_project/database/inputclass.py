from database import database

class Date:
    def __init__(self, day, month, year):
        self._day = 0
        self._month = 0
        self._year = 0
        self._dob = self.setDate(day, month, year)

    @classmethod
    def bixesto(cls, year):
        return bool((year % 4 == 0 and year % 100 != 0) or year % 400 == 0)
    
    def setDate(self, day, month, year):
        yesNo = False
        if day >= 1 and day <= 31:
            if month in [1, 3, 5, 7, 8, 10, 12]:
                yesNo = True
            elif month == 2:
                if Date.bixesto(year) and day <= 29:
                    yesNo = True
                elif day <= 28:
                    yesNo = True 
            elif day <= 30:
                yesNo = True

        if yesNo:
            self._db = f"{year:04}/{month:02}/{day:02}"
            self._day = int(day)
            self._month = int(month)
            self._year = int(year)
        else:
            self._dob = None
            print("Invalid date")
        
    def showDate(self):
        mon = None
        match self._month:
            case 1:  mon = "Jannuary"
            case 2:  mon = "February"
            case 3:  mon = "March"
            case 4:  mon = "Abril"
            case 5:  mon = "May"
            case 6:  mon = "June"
            case 7:  mon = "July"
            case 8:  mon = "Agust"
            case 9:  mon = "September"
            case 10: mon = "October"
            case 11: mon = "November"
            case 12: mon = "December"
        if mon != None:
            print(f"{mon} {self._day:02}, {self._year}")
        else:
            print("Unknown")


class Contact:
    def __init__(self, email, phone):
        self._email = email
        self._phone = phone
    
    def setEmail(self, email):
        if "@" in email:
            self._email = email
    
    def setPhone(self, phone):
        if "-" in phone:
            self._phone = phone
    
    def showContac(self):
        self._person.showPerson()
        print(f"Email........: {self._email}")
        print(f"Phone number.: {self._phone}")


class Address:
    def __init__(self, city, postal_code, street_nr, street_name):
        self.city = city
        self.postal_code = postal_code
        self._street_number = street_nr
        self._street_name = street_name



class Social:
    pass

class Bank:
    pass


class Company:
    pass


class Credential:
    pass


class Person:
    def __init__(self, fname, lname, gender):
        self._fname = None
        self._lname = None
        self._gender = None
        self.setName(fname, lname)
        self.setGender(gender)
    
    def setName(self, fname, lname):
        if len(fname) > 2 and len(lname) > 2:
            self._fname = fname
            self._lname = lname
        else:
            print("first name and last name must have at least 3 char")

    def setGender(self, gender):
        if gender in ("MmFf"):
            if self._fname != None:
                self._gender = gender
            else:
                print("Unknown person cannot have gender")
        else:
            print("Invalid Gender")


class PersonalInfo():
    def __init__(self, person: Person, dob: Date, contact: Contact):
        self._id = None
        id = database.query_ddl("SELECT MAX(personal_id) AS id FROM personal")
        if id != None:
            if self._fname != None:
                self._id = id[0][0] + 1
                self._person = person
                self._dob = dob
                self._contact = contact
        else:
            print("Erro on database")

    def showPerson(self):
        if self._fname != None:
            print(f"Id...........: {self._id}")
            print(f"Nome.........: {self._fname} {self._lname}")
            print(f"Date of Birth: ", end="")
            self.showDate()
            print("Gender.......: ", end="")
            match(self._gender):
                case "M":
                    print("Male")
                case "F":
                    print("Female")
        else:
            print("Unkown person")

