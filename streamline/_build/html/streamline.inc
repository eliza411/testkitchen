
      <div class="documentwrapper">
          <div class="body">
            
  <div class="section" id="ingredients">
<h1>1. Ingredients</h1>
<p>Test kitchen recipes are based on our sandbox setup, which includes pre-installed modules used every time. See <a class="reference external" href="http://training.opensourcery.com/sandbox/setup">http://training.opensourcery.com/sandbox/setup</a> to configure your own environment to match these instructions.</p>
<div class="section" id="prerequisite">
<h2>1.1. Prerequisite</h2>
<p>This recipe builds on Create an Event Calendar. It includes the modules, content types, and views built in that recipe.</p>
</div>
<div class="section" id="staple">
<h2>1.2. Staple</h2>
<ol class="arabic simple">
<li><a class="reference external" href="http://drupal.org/project/references">http://drupal.org/project/references</a> - Fields: Enable References</li>
<li><a class="reference external" href="http://drupal.org/project/cnr">http://drupal.org/project/cnr</a> - Corresponding Node References</li>
<li><a class="reference external" href="http://drupal.org/project/node_reference">http://drupal.org/project/node_reference</a> - Node Reference</li>
<li><a class="reference external" href="http://drupal.org/project/node_clone">http://drupal.org/project/node_clone</a> - Other: Enable Node Clone</li>
</ol>
<p>Core: Enable: Node Reference, User Reference Automatic Node titles, Location Phone, Node Locations</p>
<p>Enable Location Generate (devel)</p>
<p>Use location?</p>
<p><strong>Drush users:</strong></p>
<div class="highlight-python"><pre>drush dl references cnr node_clone location
drush en node_clone references node_reference user_reference location_cck location node_location -y</pre>
</div>
</div>
<div class="section" id="speciality">
<h2>1.3. Speciality</h2>
</div>
</div>
<div class="section" id="locations">
<h1>2. Locations</h1>
<div class="section" id="configure-the-location-module">
<h2>2.1. Configure the location module</h2>
<p><em>Configuration &gt; Content authoring &gt; Location: Main Settings</em></p>
<p>Review the settings here. The are generally usable by default.</p>
</div>
</div>
<div class="section" id="create-a-way-to-enter-venues">
<h1>3. Create a way to enter venues</h1>
<p><em>Structure &gt; Content types &gt; +Add content type</em></p>
<ol class="arabic">
<li><p class="first">Name: Location</p>
</li>
<li><p class="first">Description: Enter an location to be used when creating events</p>
</li>
<li><p class="first">Set the following values</p>
<table border="1" class="docutils">
<colgroup>
<col width="43%" />
<col width="57%" />
</colgroup>
<tbody valign="top">
<tr class="row-odd"><td><p class="first last">Submission Form Settings</p>
</td>
<td><p class="first last">Title field label: Location name</p>
</td>
</tr>
<tr class="row-even"><td><p class="first last">Publishing Options</p>
</td>
<td><p class="first last">[√] Published</p>
</td>
</tr>
<tr class="row-odd"><td><p class="first last">Display Settings</p>
</td>
<td><p class="first last">[ ] Display author and date information</p>
</td>
</tr>
<tr class="row-even"><td><p class="first last">Comment Settings</p>
</td>
<td><p class="first last">Closed</p>
</td>
</tr>
<tr class="row-odd"><td><p class="first last">Locative information</p>
</td>
<td><p class="first last">[ ] Collapsed &lt;- uncheck
Collect &lt;- Set all to Allow</p>
</td>
</tr>
<tr class="row-even"><td><p class="first last">Menu Settings</p>
</td>
<td><p class="first last">[ ] Uncheck all menus</p>
</td>
</tr>
</tbody>
</table>
</li>
</ol>
<p>#. Save and add fields
#.</p>
<div class="section" id="create-proper-paths">
<h2>3.1. Create proper paths</h2>
<p><em>Configuration &gt; Search and Metadata: URL aliases &gt; Patterns</em></p>
<p>Later on, we’ll be creating a landing page at /events, so we’re setting that as the path component now now.</p>
<ol class="arabic simple">
<li>Pattern for all Event paths: events/[node:title]</li>
<li>Save configuration</li>
</ol>
</div>
</div>
<div class="section" id="set-and-test-permissions">
<h1>4. Set and test permissions</h1>
<p>If you are not using the Test Kitchen Install Profile or if you are new to the idea of users, roles, permissions or masquerade, see <a class="reference external" href="http://training.opensourcery.com/basics">http://training.opensourcery.com/basics</a></p>
<div class="section" id="set-permissions">
<h2>4.1. Set permissions</h2>
<p><em>People &gt; Permissions</em></p>
<p>Set permissions as follows:</p>
<table border="1" class="docutils">
<colgroup>
<col width="49%" />
<col width="19%" />
<col width="10%" />
<col width="22%" />
</colgroup>
<thead valign="bottom">
<tr class="row-odd"><th class="head">Permission</th>
<th class="head">Contributor</th>
<th class="head">Editor</th>
<th class="head">Administrator</th>
</tr>
</thead>
<tbody valign="top">
<tr class="row-even"><td>Event: Create new content</td>
<td>[√]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
<tr class="row-odd"><td>Event: Edit own content</td>
<td>[√]</td>
<td>[ ]</td>
<td>[√]</td>
</tr>
<tr class="row-even"><td>Event: Edit any content</td>
<td>[ ]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
<tr class="row-odd"><td>Event: Delete own content</td>
<td>[√]</td>
<td>[ ]</td>
<td>[√]</td>
</tr>
<tr class="row-even"><td>Event: Delete any content</td>
<td>[ ]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
</tbody>
</table>
</div>
<div class="section" id="test-author-privileges">
<h2>4.2. Test Author privileges</h2>
<p>Masquerade as Test Author and ensure you CAN:</p>
<ol class="arabic simple">
<li>Create a Event</li>
<li>Edit that Event</li>
<li>Delete that Event</li>
</ol>
<p>Ensure you CANNOT:</p>
<ol class="arabic simple">
<li>Edit galleries you didn’t create</li>
<li>Delete galleries you didn’t create</li>
</ol>
<p>When you’re done, remember to Switch back</p>
</div>
<div class="section" id="test-editor-privileges">
<h2>4.3. Test Editor privileges</h2>
<p>Masquerade as Test Editor and ensure you CAN:</p>
<ol class="arabic simple">
<li>Create a Event</li>
<li>Edit that Event</li>
<li>Delete that Event</li>
<li>Edit a Event you didn’t create</li>
<li>Delete a Event you didn’t create</li>
</ol>
<table border="1" class="docutils">
<colgroup>
<col width="47%" />
<col width="53%" />
</colgroup>
<thead valign="bottom">
<tr class="row-odd"><th class="head">Resource Key</th>
<th class="head">Translation</th>
</tr>
</thead>
<tbody valign="top">
<tr class="row-even"><td>core_file_size</td>
<td>Ignored</td>
</tr>
<tr class="row-odd"><td>data_seg_size</td>
<td>Ignored</td>
</tr>
<tr class="row-even"><td>file_size</td>
<td>Ignored</td>
</tr>
<tr class="row-odd"><td>cpu_time</td>
<td>Ignored</td>
</tr>
<tr class="row-even"><td>wallclock_time</td>
<td>-l walltime= <cite>value</cite></td>
</tr>
</tbody>
</table>
</div>
</div>


          </div>
      </div>
      