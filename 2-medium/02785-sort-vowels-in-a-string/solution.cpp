class Solution {
    //checks if given char is vowel
    bool is_vowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch =='i' || ch =='o' || ch == 'u'
            || ch == 'A' || ch == 'E' || ch =='I' || ch =='O' || ch == 'U');
    }
    
public:
    string sortVowels(string s) {
    
        vector<char> vec_stack{};
        
        //save all of vowels char of current string int vector ==> but using that vector like a stack
        for (auto ch: s) {
            if (is_vowel(ch)) {
                vec_stack.push_back(ch);
            }
        }
        
        //we sort this vector first before using it ==> its reversed sort ==> using rbegin() and rend()
        sort(vec_stack.rbegin(), vec_stack.rend());
        
        //now we traverse string again and replace all vowels in it with our sorted vowels
        for (int i{0}; i < s.size(); ++i) {
            if (is_vowel(s[i])) {
                s[i] = vec_stack[vec_stack.size()-1];
                vec_stack.pop_back();
            }
        }
        
        return s;
    }
};
