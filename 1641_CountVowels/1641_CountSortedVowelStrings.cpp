class Solution {
public:
    int countvUtil(int n,int i,int &count)
	{
		if(n == 0){
			count++;
			return count;
		}

		for(int j = i; j < 5; j++)
		{
			countvUtil(n-1,j,count);
		}
        return count;
	}
    int countVowelStrings(int n) {
        vector<char> v = {'a','e','i','o','u'};
        if(n == 1){
            return 5;
        }
        int count = 0;
        return countvUtil(n,0,count);
    }
};