
      <div class="documentwrapper">
          <div class="body">
            
  <p>Does your organization require content review before the content gets published? We&#8217;ll build a common editorial workflow that allows an author to create and edit his or her own work and submit it for editorial review. Author and editor can collaborate until it&#8217;s ready to be passed along for final approval and publication.</p>
<div class="user-table container">
<div class="figure">
<img alt="Cathy Contributor Avatar" src="sites/default/files/recipes/user_icons/contributor.png" />
<p class="caption">Cathy Contributor</p>
<div class="legend">
Cathy has been assigned the Contributor role so that she will be able to create and edit her own content.</div>
</div>
<div class="figure">
<img alt="Eli Editor Avatar" src="sites/default/files/recipes/user_icons/editor.png" />
<p class="caption">Eli Editor</p>
<div class="legend">
Eli has been assigned the Editor role so that in addition to being able to do anything a contributor can do, he will be able to edit the work of others and advance content for publication.</div>
</div>
<div class="figure">
<img alt="Peggy Publisher Avatar" src="sites/default/files/recipes/user_icons/publisher.png" />
<p class="caption">Peggy Publisher</p>
<div class="legend">
Peggy has been assigned the Publisher role. This is the only role that will be able to make content live on the site. Publishers can do everything that editors and contributors can do.</div>
</div>
</div>
<div class="section" id="ingredients">
<h1>1. Ingredients</h1>
<p>Test kitchen recipes are based on our sandbox setup, which includes pre-installed modules used every time. See <a class="reference external" href="http://training.opensourcery.com/sandbox/setup">http://training.opensourcery.com/sandbox/setup</a> to configure your own environment to match these instructions.</p>
<div class="section" id="staple">
<h2>1.1. Staple</h2>
<ol class="arabic simple">
<li><a class="reference external" href="http://drupal.org/project/ctools">http://drupal.org/project/ctools</a> - Enable Chaos tools</li>
<li><a class="reference external" href="http://drupal.org/project/views">http://drupal.org/project/views</a> - Views: Enable Views and Views UI</li>
<li><a class="reference external" href="http://drupal.org/project/workbench">http://drupal.org/project/workbench</a> - Enable Workbench</li>
<li><a class="reference external" href="http://drupal.org/project/workbench_moderation">http://drupal.org/project/workbench_moderation</a> - Enable Workbench Moderation</li>
<li><a class="reference external" href="http://drupal.org/project/diff">http://drupal.org/project/diff</a> - Enable Diff</li>
</ol>
<p><strong>Drush users:</strong></p>
<div class="highlight-python"><pre>drush dl ctools views workbench workbench_moderation diff
drush en ctools views views_ui workbench workbench_moderation diff -y</pre>
</div>
</div>
</div>
<div class="no-break section" id="users-and-permissions">
<h1>2. Users and permissions</h1>
<p><em>People &gt; Permissions</em></p>
<p>We&#8217;re working with three pre-created users, each of whom is assigned to one of the three pre-created roles that will be used in the workflow. Creating users and roles is routine, but permissions are one of the trickiest things to get right, so that&#8217;s where we&#8217;ll begin.</p>
<div class="section" id="node-permissions">
<h2>2.1. Node permissions</h2>
<p>Before setting up the second layer of permissions provided by Workbench Moderation, we&#8217;ll set the basic node permissions. These settings are based on the premise that no site content is ever deleted. During development, you might choose to allow the deletion of content.</p>
<table border="1" class="docutils">
<colgroup>
<col width="54%" />
<col width="20%" />
<col width="11%" />
<col width="16%" />
</colgroup>
<thead valign="bottom">
<tr class="row-odd"><th class="head">Permission</th>
<th class="head">Contributor</th>
<th class="head">Editor</th>
<th class="head">Publisher</th>
</tr>
</thead>
<tbody valign="top">
<tr class="row-even"><td>View own unpublished content</td>
<td>[√]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
<tr class="row-odd"><td>View content revisions</td>
<td>[√]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
<tr class="row-even"><td>Revert content revisions</td>
<td>[ ]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
<tr class="row-odd"><td>Delete content revisions</td>
<td>[ ]</td>
<td>[ ]</td>
<td>[ ]</td>
</tr>
<tr class="row-even"><td>Article: Create new content</td>
<td>[√]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
<tr class="row-odd"><td>Article: Edit own content</td>
<td>[√]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
<tr class="row-even"><td>Article: Edit any content</td>
<td>[ ]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
<tr class="row-odd"><td>Article: Delete own content</td>
<td>[ ]</td>
<td>[ ]</td>
<td>[ ]</td>
</tr>
<tr class="row-even"><td>Article: Delete any content</td>
<td>[ ]</td>
<td>[ ]</td>
<td>[ ]</td>
</tr>
<tr class="row-odd"><td>Basic page: Create new content</td>
<td>[√]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
<tr class="row-even"><td>Basic page: Edit own content</td>
<td>[√]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
<tr class="row-odd"><td>Basic page: Edit any content</td>
<td>[ ]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
<tr class="row-even"><td>Basic page: Delete own content</td>
<td>[ ]</td>
<td>[ ]</td>
<td>[√]</td>
</tr>
<tr class="row-odd"><td>Basic page: Delete any content</td>
<td>[ ]</td>
<td>[ ]</td>
<td>[√]</td>
</tr>
</tbody>
</table>
</div>
</div>
<div class="section" id="configure-workbench-moderation">
<h1>3. Configure workbench moderation</h1>
<div class="section" id="review-configuration">
<h2>3.1. Review configuration</h2>
<p><em>Configuration &gt; Workbench: Workbench Moderation</em></p>
<img alt="ites/default/files/recipes/moderation/workflow_simple.png" class="align-left" src="ites/default/files/recipes/moderation/workflow_simple.png" />
<p>We will start by using the default states provided by Workbench Moderation and later add new ones. These states are adequate for the simple workflow pictured here. When we add a third role for review prior to publication, then we&#8217;ll need to make adjustments.</p>
</div>
<div class="section" id="enable-the-workflow-for-content-types">
<h2>3.2. Enable the workflow for content types</h2>
<p><em>Structure &gt; Content types &gt; Article: edit</em></p>
<div class="tip container">
Although we don&#8217;t cover this today, it is possible to moderate content on a per-content-type basis. This gets complex very quickly! See <a class="reference external" href="http://drupal.org/node/1206854#comment-5241230">http://drupal.org/node/1206854#comment-5241230</a> for how to enable this.</div>
<ol class="arabic simple">
<li>Publishing options</li>
<li>[ ] Published (Uncheck this)</li>
<li>[√] Promoted to front page (Leave checked)</li>
<li>[ ] Sticky at top of lists (Leave unchecked)</li>
<li>[√] Create a new revision (Check this!)</li>
<li>[√] Enable moderation of revisions (Can only be checked once the item above is checked. Check this).</li>
<li>Default moderation state: Draft</li>
<li>Save content type</li>
<li>Repeat for the Basic page content type (although don&#8217;t promote pages to the front page)</li>
</ol>
</div>
<div class="section" id="set-the-workbench-moderation-permissions">
<h2>3.3. Set the Workbench Moderation permissions</h2>
<p><em>People &gt; Permissions</em></p>
<p>At the bottom of the Permissions page:</p>
<p><strong>Workbench</strong></p>
<table border="1" class="docutils">
<colgroup>
<col width="66%" />
<col width="14%" />
<col width="8%" />
<col width="12%" />
</colgroup>
<thead valign="bottom">
<tr class="row-odd"><th class="head">Permission</th>
<th class="head">Contributor</th>
<th class="head">Editor</th>
<th class="head">Publisher</th>
</tr>
</thead>
<tbody valign="top">
<tr class="row-even"><td>Administer Workbench settings</td>
<td>[ ]</td>
<td>[ ]</td>
<td>[ ]</td>
</tr>
<tr class="row-odd"><td>Access My Workbench</td>
<td>[√]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
</tbody>
</table>
<p><strong>Workbench Moderation</strong></p>
<table border="1" class="docutils">
<colgroup>
<col width="66%" />
<col width="14%" />
<col width="8%" />
<col width="12%" />
</colgroup>
<thead valign="bottom">
<tr class="row-odd"><th class="head">Permission</th>
<th class="head">Contributor</th>
<th class="head">Editor</th>
<th class="head">Publisher</th>
</tr>
</thead>
<tbody valign="top">
<tr class="row-even"><td>View all unpublished content</td>
<td>[ ]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
<tr class="row-odd"><td>Administer Workbench Moderation</td>
<td>[ ]</td>
<td>[ ]</td>
<td>[ ]</td>
</tr>
<tr class="row-even"><td>Bypass moderation restrictions</td>
<td>[ ]</td>
<td>[ ]</td>
<td>[ ]</td>
</tr>
<tr class="row-odd"><td>View moderation history</td>
<td>[√]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
<tr class="row-even"><td>View the moderation messages on a node</td>
<td>[√]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
<tr class="row-odd"><td>Use &#8220;My Drafts&#8221; workbench tab</td>
<td>[√]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
<tr class="row-even"><td>Use &#8220;Needs Review&#8221; workbench tab</td>
<td>[ ]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
<tr class="row-odd"><td>Moderate all content from Draft to Needs Review *</td>
<td>[√]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
<tr class="row-even"><td>Moderate all content from  Needs Review to Draft</td>
<td>[ ]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
<tr class="row-odd"><td>Moderate all content from Needs Review to Published</td>
<td>[ ]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
</tbody>
</table>
<p>* It&#8217;s oddly worded, but you must grant this permission to the Contributor. It really means &#8220;Moderate all content types to Needs review.&#8221; It is limited in scope by your particular permissions for each content type. The Contributor role is only allowed to edit its own Articles and Basic Pages, so it Cathy Contributor won&#8217;t be able to Moderate other peoples&#8217; work.</p>
</div>
<div class="section" id="check-your-permissions">
<h2>3.4. Check your permissions</h2>
<p><em>Configuration &gt; Workbench: Workbench Moderation &gt; Check permissions (tab)</em></p>
<p>Workbench has a great feature to help ensure you&#8217;ve set up your transitions properly. Test both to be sure that each role can do what you want and also that no roles can do things they&#8217;re not supposed to.</p>
</div>
</div>
<div class="section" id="watch-contributor-editor-moderation-in-action">
<h1>4. Watch Contributor &gt; Editor Moderation in Action</h1>
<p><em>Home</em></p>
<p>We&#8217;re going to set up in two separate browsers, once for Cathy Contributor and one for Eli Editor so that we can watch as content progresses through the workflow.</p>
<div class="section" id="create-an-article-as-cathy-contributor">
<h2>4.1. Create an article as Cathy Contributor</h2>
<div class="users container">
<div class="figure">
<img alt="sites/default/files/recipes/user_icons/contributor.png" src="sites/default/files/recipes/user_icons/contributor.png" />
<div class="legend">
<ol class="arabic simple">
<li>In the first browser, log in as admin and masquerade as Cathy Contributor.</li>
<li>Create a new article titled Contributor FAQ</li>
<li>Note the message that the draft will be placed in moderation.</li>
</ol>
</div>
</div>
</div>
</div>
<div class="section" id="view-eli-editor-s-worbench">
<h2>4.2. View Eli Editor&#8217;s Worbench</h2>
<p><em>My Workbench &gt; Needs Review (tab)</em></p>
<div class="users container">
<div class="figure">
<img alt="sites/default/files/recipes/user_icons/editor.png" src="sites/default/files/recipes/user_icons/editor.png" />
<div class="legend">
<p>To save yourself the tedium of logging in and out or even masquerading back and forth, we recommend you install a second browser on your system, if you don&#8217;t already have one.</p>
<ol class="arabic simple">
<li>In the second browser, log in as admin and masquerade as Eli Editor.</li>
<li>View My Workbench &gt; Needs Review (tab)</li>
<li>You shouldn&#8217;t see anything yet.</li>
</ol>
</div>
</div>
</div>
</div>
<div class="section" id="move-cathy-s-work-to-needs-review">
<h2>4.3. Move Cathy&#8217;s work to Needs Review</h2>
<p><em>Workbench &gt; My Drafts</em></p>
<div class="users container">
<div class="figure">
<img alt="sites/default/files/recipes/user_icons/contributor.png" src="sites/default/files/recipes/user_icons/contributor.png" />
<div class="legend">
<p>Cathy Contributor can move her work from Draft to Needs Review in three places:</p>
<ul class="simple">
<li>On the View draft tab of the node, just as soon as she&#8217;s saved it</li>
<li>On the Moderate tab, where the entire revision history is available</li>
<li>From the My Drafts page</li>
</ul>
<p>Her work will be visible to no one but an administrator until she moves it to the Needs Review state.</p>
<ol class="arabic simple">
<li>Move the article created in 3.1, Contributor FAQ, into the Needs Review state.</li>
</ol>
</div>
</div>
</div>
<ol class="page-break arabic simple" start="2">
<li>Note that it disappears from Drafts and reappears on the My content page in My Edits. If Cathy bookmarks the page, she can still edit this while it&#8217;s in the Needs review state, good for fixing that last typo.</li>
</ol>
</div>
<div class="section" id="publish-cathy-s-article">
<h2>4.4. Publish Cathy&#8217;s article</h2>
<p><em>My Workbench &gt; Needs Review (tab)</em></p>
<div class="users container">
<div class="figure">
<img alt="sites/default/files/recipes/user_icons/editor.png" src="sites/default/files/recipes/user_icons/editor.png" />
<div class="legend">
<ol class="arabic simple">
<li>Reload Eli Editor&#8217;s Needs Review tab.</li>
<li>Locate Cathy&#8217;s new article.</li>
<li>Publish it.</li>
</ol>
</div>
</div>
</div>
</div>
<div class="section" id="as-cathy-review-the-published-work">
<h2>4.5. As Cathy, review the published work</h2>
<p><em>My Workbench</em>:</p>
<div class="users container">
<div class="figure">
<img alt="sites/default/files/recipes/user_icons/contributor.png" src="sites/default/files/recipes/user_icons/contributor.png" />
<div class="legend">
<ol class="arabic simple">
<li>Take a look at Cathy&#8217;s main workbench page.</li>
<li>Edit the Contributor FAQ</li>
<li>Note that the officially-approved content stays published while this draft goes into moderation.</li>
</ol>
</div>
</div>
</div>
</div>
<div class="section" id="experiment">
<h2>4.6. Experiment</h2>
<ol class="arabic simple">
<li>Try routing the article between Cathy and Eli in ways your organization might use workflow.</li>
<li>Try creating content as Eli.</li>
<li>Switch back to the admin account when you&#8217;re done.</li>
</ol>
<div class="question container">
What if Eli would like to return the article to Cathy because it needs work? He can send it back by setting it to Draft, but out of the box, it&#8217;s difficult to add a message to the page. We&#8217;ll fix that as best we can in the section <a class="reference internal" href="#views"><em>Adjust the views</em></a>. There is a feature request to make it easier to add comments at <a class="reference external" href="http://drupal.org/node/1257650">http://drupal.org/node/1257650</a>.</div>
</div>
</div>
<div class="section" id="expanding-the-workflow">
<h1>5. Expanding the Workflow</h1>
<div class="section" id="add-a-new-state">
<h2>5.1. Add a new state</h2>
<p><em>Configuration &gt; Workbench: Workbench Moderation</em></p>
<div class="figure">
<img alt="sites/default/files/recipes/moderation/workflow.png" src="sites/default/files/recipes/moderation/workflow.png" />
<div class="legend">
<p>To add the publisher into the mix, we need a state for content that has been approved by the editor and needs a final review by the publisher.</p>
<p>On the main screen, add a state:</p>
<blockquote>
<div><ol class="arabic">
<li><p class="first">Name: Needs Final Review</p>
</li>
<li><p class="first">Description: Ready for Publication</p>
</li>
<li><p class="first">Arrange them in order using the grabber</p>
<blockquote>
<div><ul class="simple">
<li>Draft</li>
<li>Needs Review</li>
<li>Needs Final Review</li>
<li>Published</li>
</ul>
</div></blockquote>
</li>
</ol>
<ol class="arabic simple" start="4">
<li>Save</li>
</ol>
</div></blockquote>
</div>
</div>
<div class="note-error container">
<p>When you save, you&#8217;ll see the following warning:</p>
<p class="warning">Depending on the changes you have made it may be necessary to reconfigure Views that leverage Workbench Moderation such as workbench_moderation.</p>
<p>In the section <a class="reference internal" href="#views"><em>Adjust the views</em></a> will address the customizations necessary to take advantage of our new state.</p>
</div>
</div>
<div class="section" id="enable-the-transitions">
<h2>5.2. Enable the transitions</h2>
<p><em>Configuration &gt; Workbench: Workbench Moderation: Transitions (tab)</em></p>
<p>Next we define the transitions:</p>
<p>Allow us to give editors permission to advance content to publishers.</p>
<ol class="arabic simple">
<li>Needs Review &gt; Needs Final Review</li>
<li>Save</li>
</ol>
<p>Allow us to give publishers the ability to send the content back to the editors.</p>
<ol class="arabic simple">
<li>Needs Final Review &gt; Needs Review</li>
<li>Save</li>
</ol>
<p>Allow us to give the publisher permission to publish.</p>
<ol class="arabic simple">
<li>Needs Final Review &gt; Published</li>
<li>Save</li>
</ol>
<p class="page-break">Remove an editor&#8217;s ability to publish without final review.</p>
<ol class="arabic simple">
<li>Needs Review &gt; Published &lt;- Check delete</li>
<li>Save</li>
</ol>
</div>
<div class="section" id="assign-transition-permissions">
<h2>5.3. Assign transition permissions</h2>
<p><em>People &gt; Permissions</em></p>
<p>Set permissions for the new states as follows.</p>
<p><strong>Workbench Moderation</strong></p>
<table border="1" class="docutils">
<colgroup>
<col width="70%" />
<col width="13%" />
<col width="7%" />
<col width="10%" />
</colgroup>
<thead valign="bottom">
<tr class="row-odd"><th class="head">Permission</th>
<th class="head">Contributor</th>
<th class="head">Editor</th>
<th class="head">Publisher</th>
</tr>
</thead>
<tbody valign="top">
<tr class="row-even"><td>Moderate all content from Needs Review to Needs Final Review</td>
<td>[ ]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
<tr class="row-odd"><td>Moderate all content from Needs Final Review to Needs Review</td>
<td>[ ]</td>
<td>[ ]</td>
<td>[√]</td>
</tr>
<tr class="row-even"><td>Moderate all content from Needs Final Review to Published</td>
<td>[ ]</td>
<td>[ ]</td>
<td>[√]</td>
</tr>
</tbody>
</table>
</div>
</div>
<div class="section" id="adjust-the-views">
<span id="views"></span><h1>6. Adjust the views</h1>
<p>Since we added our own state, we&#8217;ll need to create another tab that is visible to the Publisher.</p>
<div class="section" id="add-an-administration-page-for-publishers">
<h2>6.1. Add an administration page for publishers</h2>
<p><em>Structure &gt; Views &gt; workbench_moderation: edit</em></p>
<div class="section" id="displays">
<h3>6.1.1. Displays</h3>
<p>This is a critically important step. Be sure you&#8217;re working with the display you think you are!</p>
<ol class="arabic simple">
<li>Click Needs Review Page</li>
</ol>
</div>
<div class="section" id="needs-review-page-details">
<h3>6.1.2. Needs Review Page details</h3>
<ol class="arabic simple">
<li>Click the arrow next to view needs review page</li>
<li>Choose clone needs review page</li>
<li>Display Name: Needs Review Page &lt;- click the words</li>
<li>Name: Needs Final Review</li>
<li>Apply</li>
</ol>
</div>
<div class="section" id="title">
<h3>6.1.3. Title</h3>
<ol class="arabic simple">
<li>Click Needs Review</li>
<li>For this page (override)</li>
<li>Change to say Needs Final Review</li>
<li>Apply (this display)</li>
</ol>
</div>
<div class="section" id="filter-criteria">
<h3>6.1.4. Filter Criteria</h3>
<ol class="arabic simple">
<li>Click Workbench Moderation State: Needs Review</li>
<li>For: This page (override)</li>
<li>[ ] Needs Review &lt;- uncheck this</li>
<li>[√] Needs Final Review &lt;- check this instead</li>
<li>Apply (this display)</li>
</ol>
</div>
<div class="section" id="page-settings">
<h3>6.1.5. Page Settings</h3>
<div class="section" id="path">
<h4>Path:</h4>
<ol class="arabic simple">
<li>Click admin/workbench/r...</li>
<li>admin/workbench/needs-final</li>
<li>Apply</li>
</ol>
</div>
<div class="section" id="menu">
<h4>Menu:</h4>
<ol class="arabic simple">
<li>Click Tab: Needs Review</li>
<li>(*) Menu tab &lt;- leave selected</li>
<li>Title: Needs Final Review</li>
<li>Menu: Navigation</li>
<li>Weight: 99</li>
<li>Apply</li>
</ol>
</div>
<div class="section" id="access">
<h4>Access:</h4>
<ol class="arabic simple">
<li>Click Permissions</li>
<li>For: This page (override)</li>
<li>(*) Role</li>
<li>Apply (this display)</li>
<li>[√] publisher</li>
<li>Apply (this display)</li>
<li>Save the view</li>
</ol>
</div>
</div>
<div class="section" id="fields">
<h3>6.1.6. Fields</h3>
<p>It&#8217;s difficult to find view and edit links until something is actually published, yet that&#8217;s the only way to leave a log message. Here we add edit and view links.</p>
<div class="section" id="create-a-link-to-make-leaving-log-messages-easier">
<h4>Create a link to make leaving log messages easier</h4>
<ol class="arabic simple">
<li>add &gt; Content: Nid</li>
<li>Apply (all displays)</li>
<li>Aggregation type: Group results together</li>
<li>Apply and continue</li>
<li>Label: Change from Nid to Action</li>
<li>Expand Rewrite results</li>
<li>[√] Rewrite the output of this field</li>
<li>Apply (all displays)</li>
<li>Save the view</li>
</ol>
</div>
</div>
<div class="section" id="advanced-no-results-behavior">
<h3>6.1.7. Advanced: No Results Behavior</h3>
<ol class="arabic simple">
<li>Click Global: Text area</li>
<li>For: This page (override)</li>
<li>Change &#8220;Needs Review&#8221; in the text area so it says &#8220;Needs Final Review&#8221;</li>
<li>Apply (this display)</li>
</ol>
</div>
</div>
</div>
<div class="section" id="watch-editor-publisher-moderation-in-action">
<h1>7. Watch Editor/Publisher Moderation in Action</h1>
<div class="section" id="create-an-article-as-eli-editor">
<h2>7.1. Create an article as Eli Editor</h2>
<p><em>Home</em></p>
<div class="users container">
<div class="figure">
<img alt="sites/default/files/recipes/user_icons/editor.png" src="sites/default/files/recipes/user_icons/editor.png" />
<div class="legend">
<ol class="arabic simple">
<li>In the first browser, log in as admin and masquerade as Eli Editor.</li>
<li>Create a new article
Title: Editorial Policies
Body:  Just because you <em>can</em> move your work without review by another editor may not mean you should.</li>
<li>Save</li>
<li>Move it directly to Needs Final Review</li>
</ol>
</div>
</div>
</div>
</div>
<div class="section" id="view-peggy-publisher-s-workbench">
<h2>7.2. View Peggy Publisher&#8217;s Workbench</h2>
<p><em>My Workbench &gt; Needs Review (tab)</em></p>
<div class="users container">
<div class="figure">
<img alt="sites/default/files/recipes/user_icons/publisher.png" src="sites/default/files/recipes/user_icons/publisher.png" />
<div class="legend">
<ol class="arabic simple">
<li>In the second browser, log in as admin and masquerade as Peggy Publisher.</li>
<li>View My Workbench &gt; Needs Final Review (tab)</li>
<li>Publish Eli&#8217;s Editorial Policies article.</li>
</ol>
</div>
</div>
</div>
</div>
</div>
<div class="section" id="design-your-own-workflow">
<h1>8. Design your own workflow</h1>
<p>Extend your understanding by working on one of the following:</p>
<ol class="arabic simple">
<li>Allow the publisher to unpublish content.</li>
<li>Alter the workflow to fit your organization</li>
<li>Add features to the workbench views.</li>
</ol>
</div>


          </div>
      </div>
      