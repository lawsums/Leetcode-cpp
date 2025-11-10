<p>You are given two strings <code>word1</code> and <code>word2</code>.</p>

<p>A string <code>x</code> is called <strong>valid</strong> if <code>x</code> can be rearranged to have <code>word2</code> as a <span data-keyword="string-prefix">prefix</span>.</p>

<p>Return the total number of <strong>valid</strong> <span data-keyword="substring-nonempty">substrings</span> of <code>word1</code>.</p>

<p><strong>Note</strong> that the memory limits in this problem are <strong>smaller</strong> than usual, so you <strong>must</strong> implement a solution with a <em>linear</em> runtime complexity.</p>

<p>&nbsp;</p> 
<p><strong class="example">Example 1:</strong></p>

<div class="example-block"> 
 <p><strong>Input:</strong> <span class="example-io">word1 = "bcca", word2 = "abc"</span></p> 
</div>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<p>The only valid substring is <code>"bcca"</code> which can be rearranged to <code>"abcc"</code> having <code>"abc"</code> as a prefix.</p>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block"> 
 <p><strong>Input:</strong> <span class="example-io">word1 = "abcabc", word2 = "abc"</span></p> 
</div>

<p><strong>Output:</strong> <span class="example-io">10</span></p>

<p><strong>Explanation:</strong></p>

<p>All the substrings except substrings of size 1 and size 2 are valid.</p>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block"> 
 <p><strong>Input:</strong> <span class="example-io">word1 = "abcabc", word2 = "aaabc"</span></p> 
</div>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p>&nbsp;</p> 
<p><strong>Constraints:</strong></p>

<ul> 
 <li><code>1 &lt;= word1.length &lt;= 10<sup>6</sup></code></li> 
 <li><code>1 &lt;= word2.length &lt;= 10<sup>4</sup></code></li> 
 <li><code>word1</code> and <code>word2</code> consist only of lowercase English letters.</li> 
</ul>

<div><div>Related Topics</div><div><li>哈希表</li><li>字符串</li><li>滑动窗口</li></div></div><br><div><li>👍 45</li><li>👎 0</li></div>