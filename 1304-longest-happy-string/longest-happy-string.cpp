class Solution {
public:
    typedef pair<int,char> P;
    string longestDiverseString(int a, int b, int c) {
        priority_queue<P,vector<P>> pq;

        if(a>0){
          pq.push({a,'a'});
        }
        if(b>0){
            pq.push({b,'b'});
        }
        if(c>0){
            pq.push({c,'c'});
        }

        string result = "";
        while(!pq.empty()){
            int currentCount = pq.top().first;
            int currentChar = pq.top().second;
            pq.pop();

            if(result.length() >= 2 && result[result.length() - 1] == currentChar 
              && result[result.length() - 2] == currentChar){
                if(pq.empty()){
                    break;
                }

                int nextCount = pq.top().first;
                int nextChar = pq.top().second;
                pq.pop();
                result.push_back(nextChar);
                nextCount--;
                if(nextCount > 0){
                    pq.push({nextCount, nextChar});
                }
                
            } else {
                currentCount--;
                result.push_back(currentChar);
            }
            if(currentCount > 0){
                pq.push({currentCount, currentChar});
            }
        }
        return result;
    }
};