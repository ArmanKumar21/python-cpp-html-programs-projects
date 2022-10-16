int ladder = arr[0], stairs = arr[0];
        int jump = 1;

        if(n <= 1)
            return 0;
        
        if(arr[0] == 0)
            return -1;
        
        for(int pos = 1; pos < n; pos++){
            if(pos == n-1)
                return jump;
                
            if(ladder < arr[pos]+pos)
                ladder = arr[pos]+pos;
                
            stairs--;
            
            if(stairs == 0){
                jump++;
                stairs = ladder - pos;
                
                if(stairs == 0)
                    return -1;
            }
        }
        
        return jump;
