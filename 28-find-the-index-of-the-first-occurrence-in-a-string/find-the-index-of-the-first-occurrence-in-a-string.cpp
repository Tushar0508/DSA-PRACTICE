class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() > haystack.size()){
            return -1;
        }
        int front_slide = 0, back_slide= needle.size() -1;
        while(back_slide != haystack.size()){
            string str;
            for(int x = front_slide; x <= back_slide; x++){
                str += haystack[x];
            }
            if(str == needle){
                return front_slide;
            }
            front_slide++;
            back_slide++;
        }
    return -1;
    }
};