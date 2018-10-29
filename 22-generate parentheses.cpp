class Solution {
private:
    void generate(int left, int right, vector<string> &res, string temp){
        if(left == 0 && right == 0){
            res.push_back(temp);
        }
        if(left > 0){
            generate(left - 1, right, res, temp + '(');
        }
        if(right > 0 && left < right){
            generate(left, right - 1, res, temp + ')');
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;    
        string temp;
        generate(n, n, res, temp);
        return res;
    }
};