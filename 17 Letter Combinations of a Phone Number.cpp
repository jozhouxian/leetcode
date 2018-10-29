class Solution {

public:
    vector<string> letterCombinations(string digits){
        vector<string> res;
        if (digits.size() == 0){
            return res;
        }
        string temp;
        dfs(temp,digits,res);
        return res;
    };
    Solution() {
        keymaps = vector<string> {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    };
private:
    vector<string> keymaps;
    void dfs(string &temp, string &digits, vector<string> &res){
        int  t_index = temp.size();
        if(t_index == digits.size()){
            res.push_back(temp);
            return;
        }

        int index = digits[t_index] - '0';
        for (int i = 0; i < this->keymaps[index].size(); ++i) {
            temp.push_back(this->keymaps[index][i]);
            dfs(temp, digits, res);
            temp.pop_back();
        }
    }
};