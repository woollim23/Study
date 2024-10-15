using System;

public class Solution 
{
        public int solution(int a, int b)
        {
            int answer = 0;

            string temp = a.ToString() + b.ToString();
            string temp2 = b.ToString() + a.ToString();

            if(int.Parse(temp) >= int.Parse(temp2))
                answer = int.Parse(temp);
            else
                answer = int.Parse(temp2);

            return answer;
        }
}