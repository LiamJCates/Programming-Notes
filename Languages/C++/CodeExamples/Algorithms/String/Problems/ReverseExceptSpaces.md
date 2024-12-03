reverse a string while maintaining the spaces (if any) in their original place.

std::string solve(std::string s){
    std::string st = "";
    for (int i = s.length()-1; i >= 0; --i){
        if (s[i] != ' ')           st += s[i];
        if (s[st.length()] == ' ') st += s[st.length()];
    }
    return st;
}
