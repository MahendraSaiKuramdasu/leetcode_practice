def lastThree(j, num):
    a = 0
    b = 0
    c = 0
    if j >= 0:
        a = int(num[j])
    if j-1 >= 0:
        b = int(num[j-1])
    if j-2 >= 0:
        c = int(num[j-2])
        
    if a == 0 and b == 0 and c == 0:
        return False
    
    return True

class Solution:
    def numberToWords(self, n: int) -> str:
        ones = ["", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"]
        tens = ["", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        term = ["", "Thousand", "Million", "Billion", "Trillion"]
        teens = ["Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
        
        if n == 0:
            return "Zero"
        
        num = str(n)
        n = len(num)
        res = []
        cnt = 0
        isContinue = False
        for j in range(n-1, -1, -1):
            
            if isContinue == True:
                isContinue = False
                continue
            
            if cnt > 0 and isTerm == True:
                check = lastThree(j, num)
                if check == True:
                    res.append(term[cnt])
                isTerm = False
                
            stand = (n-1-j)%3
            i = int(num[j])
            
            if stand == 0:
                if j-1 != -1 and num[j-1] == '1':
                    res.append(teens[i])
                    isContinue = True
                else:
                    res.append(ones[i])
            elif stand == 1:
                res.append(tens[i])
            elif stand == 2:
                cnt+=1
                isTerm = True
                if i != 0:
                    res.append("Hundred")
                    res.append(ones[i])
        
        ans = ""
            
        for i in range(len(res)-1, -1, -1):
            if res[i] == "":
                continue
            if i == 0:
                ans = ans + res[i]
            else:
                ans = ans + res[i] + " "
        
        if ans[len(ans)-1] == " ":
            ans = ans[0:len(ans)-1]
        
        return ans
        