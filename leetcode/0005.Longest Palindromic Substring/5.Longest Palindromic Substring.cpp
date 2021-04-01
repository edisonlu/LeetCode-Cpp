class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1)
		{
			return s;
		}
        //built new s
		string ns;
		ns.push_back('#');
		for (auto i : s)
		{
			ns.push_back(i);
			ns.push_back('#');
		}
        //mark palindrome center
		int maxIndex = 0;
		int maxStep = 0;
        int len = ns.size();
        //record left and right border
        int l = 0, r = 0;
		for (int i = 0; i < len; ++i)
		{
			l = i - 1;
			r = i + 1;
			int step = 0;
			while (l >= 0 && r < len)
			{
				if (ns[l] != ns[r])
				{
					break;
				}
				step++;
				l--;
				r++;
			}
			if (step > maxStep)
			{
				maxStep = step;
				maxIndex = i;
			}
            //The remaining length is less than half of the current maximum palindrome length
            if(maxStep / 2 > len - i)
                break;
		}
		return s.substr(maxIndex / 2 - maxStep / 2, maxStep);
    }
};
