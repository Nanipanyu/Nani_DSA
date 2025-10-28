// 1)  In finding the max subarray length with some conditions(like sum <= k,atmost 2elements), use map technique
//             if(mp.size()>2){
//                 mp[fruits[l]]--;
//                 if(mp[fruits[l]]==0){
//                     mp.erase(fruits[l]);
//                 }
//                 l++;
//             }
//             maxlength=max(maxlength,(r-l+1));


// 2) in finding the total no of valid subarrays with some conditions use the formula (<=condition)-(<=condition-1)
//     int greaterans = count(nums,goal); 
//     int smallerans = count(nums,goal-1);
//     return (greaterans-smallerans); //if (sum<=goal)-(sum<=goal-1) we get the sum=goal count;
//in the while loop, whatver you are counting(it should be  >goal), then move the left pointer


// 3) Look at min window substring , it is a variation of min substring problem, but because of duplicates in substring we have to use a count variable to check when we have a valid window,