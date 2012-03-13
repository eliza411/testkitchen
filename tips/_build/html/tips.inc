
      <div class="documentwrapper">
          <div class="body">
            
  <div class="section" id="embedding-youtube-videos">
<h1>1. Embedding YouTube Videos</h1>
<p>When you&#8217;re viewing the video on YouTube, e.g.::
<a class="reference external" href="http://www.youtube.com/watch?v=P8FlmTlmdzc">http://www.youtube.com/watch?v=P8FlmTlmdzc</a></p>
<ol class="arabic">
<li><p class="first">Click the Share button</p>
</li>
<li><p class="first">Click the Embed button</p>
</li>
<li><p class="first">Copy the embed code.</p>
<img alt="sites/default/files/recipes/tips/youtube.png" src="sites/default/files/recipes/tips/youtube.png" />
</li>
</ol>
<ol class="arabic" start="4">
<li><p class="first">Edit the page, blog, or other content type where you want to embed the video.</p>
</li>
<li><p class="first">Disable the rich-text editor.</p>
<img alt="sites/default/files/recipes/tips/disable-rich-text.png" src="sites/default/files/recipes/tips/disable-rich-text.png" />
</li>
<li><p class="first">Paste in the embed code.</p>
</li>
<li><p class="first">To avoid issues with Chrome, you&#8217;ll add some information in the embed code. For example, the embed code of the video above is:</p>
</li>
</ol>
<blockquote>
<div><p>&lt;iframe width=&#8221;560&#8221; height=&#8221;315&#8221; src=&#8221;<a class="reference external" href="http://www.youtube.com/embed/P8FlmTlmdzc">http://www.youtube.com/embed/P8FlmTlmdzc</a>&#8221; frameborder=&#8221;0&#8221; allowfullscreen&gt;&lt;/iframe&gt;</p>
<p>Add ?wmode=Opaque to the end of the src url, so that the code looks like:</p>
<div class="highlight-python"><pre>&lt;iframe width="560" height="315" src="http://www.youtube.com/embed/P8FlmTlmdzc?wmode=Opaque" frameborder="0" allowfullscreen&gt;&lt;/iframe&gt;</pre>
</div>
</div></blockquote>
<ol class="arabic simple">
<li>Once you&#8217;ve pasted the code, you can Enable the rich-text editor. It&#8217;s normal not to see the embedded video until you save, but you can still highlight the shape and move it within the text by cutting and pasting.</li>
</ol>
</div>
<div class="section" id="creating-the-donor-quote-pop-up">
<h1>2. Creating the Donor Quote pop-up</h1>
<p>Normally, you&#8217;ll be editing the block with the Donor quote text and it will already contain the necessary HTML. Should that get deleted, you&#8217;ll need to add it back in.</p>
<ol class="arabic">
<li><p class="first">Disable rich text in order to directly enter HTML. If you don&#8217;t, the HTML becomes visible and doesn&#8217;t do what it&#8217;s supposed to.</p>
</li>
<li><p class="first">A link to the popup text should look like this. (You can change the visible text, Read More &amp;gt, but not the information between angle brackets &lt;&gt;:</p>
<div class="highlight-python"><pre>&lt;a class="fancybox" href="#fancybox"&gt;Read More &amp;gt;&lt;/a&gt;</pre>
</div>
</li>
<li><p class="first">The popup text goes between tags that look like:</p>
</li>
</ol>
<blockquote>
<div><dl class="docutils">
<dt>&lt;div id=&#8221;fancybox&#8221; style=&#8221;width:100%; display: inline-block;&#8221;&gt;</dt>
<dd>Text here.</dd>
</dl>
<p>&lt;/div&gt;</p>
</div></blockquote>
<p>You can change the visible text, &#8220;Text here&#8221; but not the information between the angle brackets. It&#8217;s okay for everything to be smooshed together.</p>
<p>You may need to press Enter above the popup text a time or two to ensure that it is not visible within the Donor Quote box.</p>
</div>


          </div>
      </div>
      