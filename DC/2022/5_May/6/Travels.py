class Travels:
    route=[]
    seatsAvail=[]
    def __init__(self,X):
        self.X=X
    def bookTickets(self,src,dest,count):
        t=src+dest
        if t in self.route:
            i=self.route.index(t)
            if self.seatsAvail[i]>=count:
                self.seatsAvail[i]-=count
                return True
            else:
                return False
        else:
            self.route.append(t)
            self.seatsAvail.append(self.X)
            i=self.route.index(t)
            if self.seatsAvail[i]>=count:
                self.seatsAvail[i]-=count
                return True
            else:
                return False
