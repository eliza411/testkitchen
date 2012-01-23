
      <div class="documentwrapper">
          <div class="body">
            
  <div class="section" id="ingredients">
<h1>1. Ingredients</h1>
<p>Test kitchen recipes are based on our sandbox setup, which includes pre-installed modules used every time. See <a class="reference external" href="http://training.opensourcery.com/sandbox/setup">http://training.opensourcery.com/sandbox/setup</a> to configure your own environment to match these instructions.</p>
<div class="section" id="staple">
<h2>1.1. Staple</h2>
</div>
<div class="section" id="theme">
<h2>1.2. Theme</h2>
<p><strong>Drush users:</strong></p>
<div class="highlight-python"><pre>drush dl
drush en -y</pre>
</div>
</div>
<div class="section" id="speciality">
<h2>1.3. Speciality</h2>
</div>
</div>
<div class="section" id="section-2">
<h1>2. Section 2</h1>
<div class="section" id="section-2-1">
<h2>2.1. Section 2.1</h2>
<p><em>Structure &gt; Content types &gt; +Add new content type</em></p>
<a href="http://www.youtube.com/v/4FynfGen1qI" class="colorbox-load recipe-step">Watch this step</a></div>
</div>
<div class="section" id="set-and-test-permissions">
<h1>3. Set and test permissions</h1>
<p><em>People &gt; Permissions</em></p>
<p>If you are not using the Test Kitchen Install Profile or if you are new to the idea of users, roles, permissions or masquerade, see <a class="reference external" href="http://training.opensourcery.com/basics">http://training.opensourcery.com/basics</a></p>
<div class="section" id="set-permissions">
<h2>3.1. Set permissions</h2>
<p>Set permissions as follows:</p>
<table border="1" class="docutils">
<colgroup>
<col width="32%" />
<col width="33%" />
<col width="35%" />
</colgroup>
<thead valign="bottom">
<tr class="row-odd"><th class="head">Author</th>
<th class="head">Editor</th>
<th class="head">Admin</th>
</tr>
</thead>
<tbody valign="top">
<tr class="row-even"><td>[√] Gallery: Create new content</td>
<td>[√] Gallery: Create new content</td>
<td>[√] Gallery: Create new content</td>
</tr>
<tr class="row-odd"><td>[√]  Gallery: Edit own content</td>
<td>[ ]  Gallery: Edit own content</td>
<td>[√] Gallery: Edit own content</td>
</tr>
<tr class="row-even"><td>[ ]   Gallery: Edit any content</td>
<td>[√] Gallery: Edit any content</td>
<td>[√] Gallery: Edit any content</td>
</tr>
<tr class="row-odd"><td>[√]  Gallery: Delete own content</td>
<td>[ ]  Gallery: Delete own content</td>
<td>[√] Gallery: Delete own content</td>
</tr>
<tr class="row-even"><td>[ ]   Gallery: Delete any content</td>
<td>[√]  Gallery: Delete any content</td>
<td>[√] Gallery: Delete any content</td>
</tr>
</tbody>
</table>
</div>
<div class="section" id="test-author-privileges">
<h2>3.2. Test Author privileges</h2>
<p>Masquerade as Test Author and ensure you CAN:</p>
<ol class="arabic simple">
<li>Create a gallery</li>
<li>Edit that gallery</li>
<li>Delete that gallery</li>
</ol>
<p>Ensure you CANNOT:</p>
<ol class="arabic simple">
<li>Edit galleries you didn’t create</li>
<li>Delete galleries you didn’t create</li>
</ol>
<p>When you’re done, remember to Switch back</p>
</div>
<div class="section" id="test-editor-privileges">
<h2>3.3. Test Editor privileges</h2>
<p>Masquerade as Test Editor and ensure you CAN:</p>
<ol class="arabic simple">
<li>Create a gallery</li>
<li>Edit that gallery</li>
<li>Delete that gallery</li>
<li>Edit a gallery you didn’t create</li>
<li>Delete a gallery you didn’t create</li>
</ol>
</div>
</div>


          </div>
      </div>
      