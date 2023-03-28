class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
      int msf1=0;
      int msf2=0;  
      int cur1=0;
      int cur2=0;  
      int sum1=0;
      int sum2=0;  
        
        for(int i=0;i<nums1.size();i++)
        {
            sum1+=nums1[i];
            sum2+=nums2[i];
            
            cur1+=nums2[i]-nums1[i];
            if(cur1<0) cur1=0;
            msf1 = max(msf1,cur1);
            
            cur2+=nums1[i]-nums2[i];
            if(cur2<0) cur2=0;
            msf2 = max(msf2,cur2);    

        }
        return max(sum1+msf1,sum2+msf2);
    }
};