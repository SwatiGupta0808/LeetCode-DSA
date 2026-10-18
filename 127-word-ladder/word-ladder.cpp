class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        queue<pair<string,int>> q;
        q.push({beginWord,1});

        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);

        while(!q.empty())
        {
            string word=q.front().first;
            int count=q.front().second;
            q.pop();
            if(word==endWord)
                return count;
            for(int i=0;i<word.size();i++)
            {
                char original=word[i];
                for(int j='a';j<='z';j++)
                {
                    word[i]=j;
                    if(st.find(word)!=st.end())
                    {
                        st.erase(word);
                        q.push({word,count+1});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
        
    }
};