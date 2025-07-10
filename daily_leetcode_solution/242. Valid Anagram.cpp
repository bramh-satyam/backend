class Solution {
private:
    static const int ALPHABET_COUNT = 26;   // making it static int so that it's class-wide constant; just const would make it instance constant and thus it can't be used to initialize static array.
public:
    bool isAnagram(string s, string t) {
        /*
        this function decides if the given inputs are valid anagram by incrementing while travesing through each letter of "s" and decrementing in case of "t"
        */
        int letter_counter[ALPHABET_COUNT] = {0};   // to keep track of all the alphabets in the input s and t

        // checking if the length of both s and t are different
        if(s.size() != t.size())
        {
            return false;
        }

        /*
        well its clearly mentioned in the question that the function's input is only lower case but if both upper and lower cases were allowed then this would come handy.
        (commenting to save some cycles)
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        transform(t.begin(), t.end(), t.begin(), ::tolower);
        */

        for(int index = 0; index < s.size(); index++)
        {
            letter_counter[s[index] - 'a']++;
            letter_counter[t[index] - 'a']--;
        }

        // letter_counter should be all zero if valid anagram
        for(auto count : letter_counter)
        {
            if(count != 0)
            {
                return false;
            }
        }

        return true;
        // Time: O(n), Space: O(1) — assuming lowercase only (fixed alphabet size)
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)

This solution works when all the alphabets are lowercase(which is mentioned in the question as well). But if s and t will have spaces in them then this would break as when trying to update the value in letter_counter the index won't be in the arrays causing segmentation fault.

FIX: we can use unordered_map<char, int>, we will have to add special checks if the character is space or symbol(like comma or semi-colon, cause I think we can ignore it) while taking care of all the other special characters(maybe hindi literal or something).

BONUS: we can use "isalpha(c)" function to filter out only characters in case of this solution, taking care of all the non-ASCII characters. 

Edge Case:
1. string of un-even size: taken care
2. empty string: taken care
*/



/*
BONUS: UNICODE INPUT

In the below given solution, we use "wstring" and "wchar_t" because of wide unicode characters, this solution also takes care of all the edge cases!

bool isAnagram(const std::wstring& s, const std::wstring& t){
    if(s.size() != t.size()){
        return false;
    }

    std::unordered_map<wchar_t, int> letter_counter;

    for(int index = 0; index < s.size(); index++)
    {
        letter_counter[s[index]]++;
        letter_counter[t[index]]--;
    }

    // this for loop works w/ C++17 and above
    for(const auto& [char, freq] : letter_counter)
    {
        if(freq != 0){
            return false;
        }
    }

    // this for loop works w/ C++11 and above
    for(const auto& item : letter_counter)
    {
        int count = item.second;
        if(count != 0){
            return false;
        }
    }
    
    return true;
}
*/