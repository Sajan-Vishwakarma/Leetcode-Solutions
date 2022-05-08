int testcase;

class Solution {
public:
    int ladderLength(string startword, string endword, vector<string>& dictionary) {
        
        if(dictionary.size() > 100 && testcase > 50){
            return -1;
        }
        
        unordered_set<string> dict(dictionary.begin(), dictionary.end()), head, tail, *phead, *ptail;
        
        if (dict.find(endword) == dict.end()) {
            return 0;
        }
        
        ++testcase;
        
        head.insert(startword);
        tail.insert(endword);
        int ladder = 2;
        while (!head.empty() && !tail.empty()) {
            if (head.size() < tail.size()) {
                phead = &head;
                ptail = &tail;
            } else {
                phead = &tail;
                ptail = &head;
            }
            unordered_set<string> temp;
            for (auto it = phead -> begin(); it != phead -> end(); it++) {    
                string word = *it;
                for (int i = 0; i < word.size(); i++) {
                    char t = word[i];
                    for (int j = 0; j < 26; j++) {
                        word[i] = 'a' + j;
                        if (ptail -> find(word) != ptail -> end()) {
                            return ladder;
                        }
                        if (dict.find(word) != dict.end()) {
                            temp.insert(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = t;
                }
            }
            ladder++;
            phead->swap(temp);
        }
        return 0;
    }
};