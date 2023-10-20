// Time complexity: O(n)
// Space complexity: O(n)

vector<vector<int>> insertInterval(vector<vector<int>> intervals, vector<int> newInterval){
  vector<vector<int>> output;
  int i = 0;
  while(i < intervals.size() && intervals[i][1] < newInterval[0]){
    output.push_back(intervals[i++]);
  }
  while(i < intervals.size() && intervals[i][0] <= newInterval[1]){
    newInterval[0] = min(newInterval[0], intervals[i][0]);
    newInterval[1] = max(newInterval[1], intervals[i][1]);
    i++;
  }
  output.push_back(newInterval);
  while(i < intervals.size()){
    output.push_back(intervals[i++]);
  }
  return output;
}
