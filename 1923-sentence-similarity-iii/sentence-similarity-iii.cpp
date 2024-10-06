class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) 
    {
        deque<string> st1, st2;
        stringstream ss2(s2);
        string word;
        while (ss2 >> word)
        {
            st2.push_back(word);
        }    
        stringstream ss1(s1);
        while (ss1 >> word)
        {
            st1.push_back(word);
        }
        while (st1.size() != 0 && st2.size() != 0 && (st1.front() == st2.front()))
            st1.pop_front(), st2.pop_front();
        while (st1.size() != 0 && st2.size() != 0 && (st1.back() == st2.back()))
            st1.pop_back(), st2.pop_back();
        return (st1.size() == 0) || (st2.size() == 0);
    }
};