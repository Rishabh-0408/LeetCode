class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        fives = 0
        tens = 0
        for i in range(len(bills)):
            if(bills[i] == 5):
                fives += 1
            elif(bills[i] == 10):
                if(fives == 0):
                    return False
                fives -= 1
                tens += 1
            else:
                #for 20
                if(tens > 0 and fives > 0):
                    fives -= 1
                    tens -= 1
                elif(fives >= 3):
                    fives -= 3
                else:
                    return False
        return True
        