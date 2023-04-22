from database import database

class Date:
    def __init__(self, d, m, y):
        self._day = 0
        self._month = 0
        self._year = 0
        self._dob = self.setDate(d, m, y)

    @classmethod
    def bixesto(year):
        return (year % 4 == 0 or year % 400 == 0 ) and (year % 100 != 0)
    
    def setDate(self, d, m, y):
        yesNo = False
        if d >= 1 and d <= 31:
            if m == 1 or d == 3 or d == 5 or d == 7 or d == 8 or d == 10 or d == 12:
                yesNo = True
            elif m == 2:
                if Date.bixesto(y) and d <= 29:
                    yesNo = True
                elif d <= 28:
                    yesNo = True 
            elif d <= 30:
                yesNo = True

        if yesNo:
            self._db = f"{y:04}/{m:02}/{d:02}"
            self._day = int(d)
            self._month = int(m)
            self._year = int(y)
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


class Personal(Date):
    def __init__(self, fname, lname, gender, day, month, year):
        super().__init__(day, month, year)
        self._fname = "Unknown"
        self._lname = "Unknown"
        self._gender = "Unknown"
        self._id = "Unknown"
        id = database.query_ddl("SELECT MAX(personal_id) AS id FROM personal")
        if id != None:
            self.setName(fname, lname)
            self.setGender(gender)
            if self._fname != "Unknown":
                self._id = id[0][0] + 1
        else:
            print("Erro on database")

    def setName(self, fname, lname):
        if len(fname) > 2 and len(lname) > 2:
            self._fname = fname
            self._lname = lname
        else:
            print("first name and last name must have at least 3 char")

    def setGender(self, gender):
        if gender in ("MmFf"):
            if self._fname != "Unknown":
                self._gender = gender
            else:
                print("Unknown person cannot have gender")
        else:
            print("Invalid Gender")

    def showPerson(self):
        if self._fname != "Unknown":
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


class Contact:
    pass


class Address:
    pass


class Social:
    pass


class Bank:
    pass


class Company:
    pass


class Credential:
    pass