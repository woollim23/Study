using System;

public class Solution {
    public int solution(int n, string control)
    {
        int answer = n;
        
        for(int i = 0; i < control.Length; i++)
        {
            switch(control[i])
            {
                case 'w' :
                    answer++;
                    break;
                case 's' :
                    answer--;
                    break;
                case 'd' :
                    answer += 10;
                    break;
                case 'a' :
                    answer -= 10;
                    break;
                default :
                    break;
            }
        }
        return answer;
    }
}