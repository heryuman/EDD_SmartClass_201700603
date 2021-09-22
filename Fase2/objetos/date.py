#Esta clase nos descompone la fecha que obtenemos del objeto tarea

class the_date(object):
    def __init__(self,_day,_month,_year,_hour):
        self.day=_day
        self.month=_month
        self.year=_year
        self.hour=_hour
       

    def getDay(self):
        return self.day

    def getMonth(self):
        return self.month

    def getYear(self):
        return self.year

    def getHour(self):
        return self.hour