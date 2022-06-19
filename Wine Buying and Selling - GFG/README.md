# Wine Buying and Selling
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given an array arr[] of size N represent N house&nbsp;built along a straight line with equal distance between adjacent houses. Each house have a certain number of wine and they want to buy/sell those wine to other house.Transporting one bottle of wine from one house to an adjacent house results in one unit of work. The task is to find minimum number of work is required to fullfill all the demands of those N house.</span></p>

<ol>
	<li><span style="font-size:18px">if a[i] &lt;&nbsp;0, then i<sup>th</sup> house want to sell a[i] number of wine bottle to other house.</span></li>
	<li><span style="font-size:18px">if a[i] &gt;&nbsp;0, then i<sup>th</sup> house want to buy&nbsp;a[i] number of wine bottle from&nbsp;other houses.</span></li>
</ol>

<p><span style="font-size:18px"><strong>Note:</strong> One have to print the minimum number such that, all the house can buy/sell wine to each other.<br>
It is gurranted that sum of all the elements of the array will be 0.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 5, arr[] = {5, -4, 1, -3, 1}
<strong>Output:</strong> 9
<strong>Explanation: </strong>
1<sup>th</sup> house can sell 4 wine bottel to 0<sup>th </sup>house,
total work needed 4*(1-0) = 4, new arr[] = 1,0,1,-3,1
now 3rd house can sell wine to 0<sup>th</sup>, 2<sup>th</sup> and 5<sup>th</sup>.
so total work needed = 1*(3-0)+1*(3-2)+1*(5-4) = 5
So total work will be 4+5 = 9</span></pre>

<p><span style="font-size:18px"><strong>Example 2:&nbsp;</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong> N = 5,
arr[]={-1000, -1000, -1000, 1000, 1000, 1000}
<strong>Output:</strong> 9000</span></pre>

<p><span style="font-size:18px"><strong>Your Task: &nbsp;</strong><br>
You don't need to read input or print anything. Complete the function <strong>wineSelling()</strong>&nbsp;which takes the array arr[] and its size N as input parameters and return an intger as output.</span></p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:&nbsp;</strong>O(N)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1)</span></p>

<p><br>
<span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>5</sup><br>
1 ≤ A[i] ≤ 10<sup>6</sup></span></p>
 <p></p>
            </div>