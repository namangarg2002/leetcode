class Solution {
public:
    vector<int> nextSmallerElement(vector<int> arr){
        vector<int> ans(arr.size());
        stack<int> st;

        st.push(arr.size());

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            int curr = arr[i];
            // answer find karo current ke liye
            while (st.top() != arr.size() && arr[st.top()] >= curr)
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> previousSmallerElement(vector<int> arr){
        vector<int> ans(arr.size());
        stack<int> st;
        st.push(-1);

        for (int i = 0; i < arr.size(); i++)
        {
            int curr = arr[i];
            while (st.top() != -1 && arr[st.top()] >= curr)
            {
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
    return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next = nextSmallerElement(heights);
        vector<int> prev = previousSmallerElement(heights);

        vector<int> area(next.size());

        for(int i=0; i<next.size(); i++){
            int width = next[i] - prev[i] - 1;
            int length = heights[i];

            int currArea = width * length;
            area[i] = currArea;
        }
        int maxi = INT_MIN;
        for(int i=0; i<area.size(); i++){
            maxi = max(maxi, area[i]);
        }
        return maxi;
    }
};