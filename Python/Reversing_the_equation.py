class Solution:
    def reverseEqn(self, s):
        stck=[]
        j=''
        i=0
        while i<len(s):
            if s[i].isnumeric():
                j+=s[i]
                i+=1
                if i==len(s):
                    stck.append(int(j))
            else:
                if len(j)>0:
                    stck.append(int(j))
                    j=''
                else:
                    stck.append(s[i])
                    i+=1
        q=''
        for k in stck[::-1]:
            q+=str(k)
        return q
