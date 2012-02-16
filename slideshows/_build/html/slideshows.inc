
      <div class="documentwrapper">
          <div class="body">
            
  <img alt="A completed gallery" src="sites/default/files/recipes/slideshows/balloons.png" />
<div class="section" id="ingredients">
<h1>1. Ingredients</h1>
<p>Test kitchen recipes are based on our sandbox setup, which includes pre-installed modules used every time. See <a class="reference external" href="http://training.opensourcery.com/sandbox/setup">http://training.opensourcery.com/sandbox/setup</a> to configure your own environment to match these instructions.</p>
<div class="section" id="staple">
<h2>1.1. Staple</h2>
<ol class="arabic simple">
<li><a class="reference external" href="http://drupal.org/project/ctools">http://drupal.org/project/ctools</a> - Enable Chaos Tools (all others are not needed)</li>
<li><a class="reference external" href="http://drupal.org/project/views">http://drupal.org/project/views</a> - Enable Views and Views UI</li>
<li><a class="reference external" href="http://drupal.org/project/libraries">http://drupal.org/project/libraries</a> - Enable Libraries</li>
<li><a class="reference external" href="http://drupal.org/project/views_slideshow">http://drupal.org/project/views_slideshow</a> - Enable Views Slideshow</li>
</ol>
</div>
<div class="section" id="theme">
<h2>1.2. Theme</h2>
<p>Because this recipe requires custom theming, we&#8217;re using AdaptiveTheme (which makes the site mobile-friendly), Corolla (which makes it attractive), and Footheme (which provide our ready-to-customize subtheme). Customizing footheme means security updates and new features from our base themes can be easily applied.</p>
<ol class="arabic simple">
<li><a class="reference external" href="http://drupal.org/project/adaptivetheme">http://drupal.org/project/adaptivetheme</a></li>
<li><a class="reference external" href="http://drupal.org/project/corolla">http://drupal.org/project/corolla</a></li>
<li><a class="reference external" href="http://drupal.org/project/footheme">http://drupal.org/project/footheme</a></li>
</ol>
<p><strong>Drush users:</strong></p>
<div class="highlight-python"><pre>drush dl ctools views libraries views_slideshow adaptivetheme corolla footheme
drush en ctools views views_ui libraries views_slideshow views_slideshow_cycle -y</pre>
</div>
</div>
<div class="section" id="specialty">
<h2>1.3. Specialty</h2>
<p>The Views Slideshow module uses two external libraries.</p>
<dl class="docutils">
<dt>Required for basic slideshow functionality:</dt>
<dd><ol class="first last arabic simple">
<li>Visit <a class="reference external" href="http://malsup.com/jquery/cycle/download.html">http://malsup.com/jquery/cycle/download.html</a></li>
<li>Click the link to “Cycle Plugin”</li>
<li>In your browser, choose File &gt; Save Page as &gt; jquery.cycle.all.js</li>
<li>Place in sites/all/libraries/jquery.cycle (you&#8217;ll have to create that folder) so that the final path looks like sites/all/libraries/jquery.cycle/jquery.cycle.all.js</li>
</ol>
</dd>
<dt>Required for advanced features, which include setting the speed of the slideshow:</dt>
<dd><ol class="first last arabic simple">
<li>Visit <a class="reference external" href="https://github.com/douglascrockford/JSON-js/downloads">https://github.com/douglascrockford/JSON-js/downloads</a> and download the appropriate format, .zip or .tar.gz, for your environment.</li>
<li>Extract it</li>
<li>Rename the directory (which begins with douglascrockford-) to json2</li>
<li>Place it in sites/all/libraries so that the final path looks like: sites/all/libraries/json2/json2.js</li>
</ol>
</dd>
</dl>
</div>
</div>
<div class="section" id="build-the-form-for-creating-galleries">
<h1>2. Build the form for creating galleries</h1>
<div class="section" id="add-a-new-content-type-called-gallery">
<h2>2.1. Add a new content type called Gallery</h2>
<p><em>Structure &gt; Content types &gt; +Add new content type</em></p>
<ol class="arabic simple">
<li>Name: Gallery</li>
<li>Description: Create an image gallery with slideshow controls.</li>
<li>Set the following values:</li>
</ol>
<blockquote>
<div><table border="1" class="docutils">
<colgroup>
<col width="43%" />
<col width="57%" />
</colgroup>
<tbody valign="top">
<tr class="row-odd"><td>Submission Form Settings</td>
<td>Title field label: Gallery name</td>
</tr>
<tr class="row-even"><td>Publishing Options</td>
<td>[√] Published</td>
</tr>
<tr class="row-odd"><td>Display Settings</td>
<td>[ ] Display author and date information</td>
</tr>
<tr class="row-even"><td>Comment Settings</td>
<td>Closed</td>
</tr>
<tr class="row-odd"><td>Menu Settings</td>
<td>[ ] Uncheck all menus</td>
</tr>
</tbody>
</table>
</div></blockquote>
<ol class="arabic simple" start="4">
<li>Save content type</li>
</ol>
</div>
<div class="section" id="add-an-image-field">
<h2>2.2. Add an image field</h2>
<p><em>Structure &gt; Content types &gt; Gallery &gt; Manage fields</em></p>
<div class="section" id="add-new-field">
<h3>2.2.1. Add new field</h3>
<ol class="arabic simple">
<li>Label: Gallery image</li>
<li>Field name: gallery_image</li>
<li>Type of data to store: Image</li>
<li>Form element to edit the data: Image &lt;- the default</li>
<li>Save</li>
</ol>
</div>
<div class="section" id="field-settings">
<h3>2.2.2. Field Settings</h3>
<ol class="arabic simple">
<li>Leave as is: Public files selected, no default image</li>
<li>Save</li>
</ol>
</div>
<div class="section" id="gallery-settings">
<h3>2.2.3. Gallery Settings</h3>
<p>There are a lot of settings here! Accept the defaults EXCEPT the following:</p>
<ol class="arabic simple">
<li>File directory: galleries</li>
<li>Minimum image resolution: 640 x 480 - We’re building our gallery around a common 640 x 480 resolution. By requiring images to be at least that large here, we can prevent jarring changes in size and eliminate white space between main images and thumbnails.</li>
<li>[√] Enable Title field</li>
</ol>
</div>
<div class="section" id="gallery-image-field-settings">
<h3>2.2.4. Gallery Image Field Settings</h3>
<ol class="arabic simple">
<li>Number of values: Unlimited</li>
<li>Save settings.</li>
</ol>
</div>
</div>
<div class="section" id="create-proper-paths">
<h2>2.3. Create proper paths</h2>
<p><em>Configuration &gt; Search and Metadata: URL aliases &gt; Patterns</em></p>
<p>Later on, we’ll be creating a landing page at /galleries, so we’re setting that as the path component now now.</p>
<ol class="arabic simple">
<li>Pattern for all Gallery paths: galleries/[node:title]</li>
<li>Save configuration</li>
</ol>
</div>
<div class="section" id="create-a-test-gallery">
<h2>2.4. Create a test gallery</h2>
<p><em>Content &gt; +Add content &gt; Gallery</em></p>
<div class="figure">
<img alt="Image of the Views Intro Screen" src="sites/default/files/recipes/slideshows/slideshows-test-gallery.png" />
<div class="legend">
<p>When you&#8217;re done, you should see the original sized images stacked down the page and protruding outside of the node region. Not to worry. We&#8217;ll be hiding that and replacing it with our gallery slideshow soon.</p>
<ol class="arabic simple">
<li>Gallery name: Test Gallery</li>
<li>Body text: Optional</li>
<li>Browse and upload at least 4 images, giving each one a title.</li>
<li>Check the URL pattern is what you expect, something like: <a class="reference external" href="http://tests.l/galleries/test-gallery">http://tests.l/galleries/test-gallery</a></li>
</ol>
</div>
</div>
</div>
<div class="section" id="hide-the-default-display-of-images">
<h2>2.5. Hide the default display of images</h2>
<p><em>Structure &gt; Content types &gt; Gallery &gt; Manage display</em></p>
<div class="figure">
<img alt="Image of the Views Intro Screen" src="sites/default/files/recipes/slideshows/slideshows-hide-images.png" />
<div class="legend">
<ol class="arabic simple">
<li>Set the Default display setting format for Image to Hidden.</li>
<li>Verify the Teaser display format is hidden. It should already be set that way.</li>
<li>Go to Content and view the gallery you created in the last step.</li>
<li>You should see nothing but body text you entered.</li>
</ol>
</div>
</div>
</div>
</div>
<div class="section" id="create-custom-image-sizes">
<h1>3. Create custom image sizes</h1>
<div class="section" id="main-gallery-image">
<h2>3.1. Main gallery image</h2>
<p><em>Configuration &gt; Media &gt; Image styles &gt; +Add style</em></p>
<p>We set a minimum resolution for uploading the image, but users can upload higher resolution if the wish. Using this style ensures uniform presentation within the gallery.</p>
<ol class="arabic simple">
<li>Image style name: gallery_main</li>
<li>In Effect, select the new effect Scale and crop from the drop down, then click Add</li>
<li>Width: 640</li>
<li>Height: 480</li>
<li>Click the Add effect button (Your changes are saved; the button on the next page is just for reordering the effects if there is more than one.)</li>
</ol>
</div>
<div class="section" id="gallery-thumbnails">
<h2>3.2. Gallery thumbnails</h2>
<p><em>Configuration &gt; Media &gt; Image styles &gt; +Add style</em></p>
<p>The thumbnail settings are chosen so the images stay proportional to a 640 x 480 main image and so seven thumbnails fit width-wise underneath it, with an allowance for padding.</p>
<ol class="arabic simple">
<li>Image style name: gallery_thumb</li>
<li>In Effect, choose Scale and crop, then click Add</li>
<li>Width: 80</li>
<li>Height: 60</li>
<li>Click the Add effect button</li>
</ol>
</div>
<div class="section" id="gallery-index-thumbnails">
<h2>3.3. Gallery index thumbnails</h2>
<p><em>Configuration &gt; Media &gt; Image styles &gt; +Add style</em></p>
<p>Add a third style for the index of galleries on the site.</p>
<ol class="arabic simple">
<li>Click +Add style again</li>
<li>Image style name: gallery_index</li>
<li>In Effect, choose Scale and crop, then click Add</li>
<li>Width: 160</li>
<li>Height: 120</li>
<li>Click the Add effect button</li>
</ol>
</div>
</div>
<div class="section" id="create-the-galleries">
<h1>4. Create the galleries</h1>
<p>Views delivers extraordinary power to the non-programmer, and the price is a densely-packed interface. We describe the steps below, but there&#8217;s a place where the screen cast is worth a thousand words!</p>
<div class="section" id="create-the-actual-gallery-display">
<h2>4.1. Create the actual gallery display</h2>
<p><em>Structure &gt; Views &gt; +Add new view</em></p>
<div class="section" id="intro-page">
<h3>4.1.1. Intro page</h3>
<div class="figure">
<img alt="Image of the Views Intro Screen" src="sites/default/files/recipes/slideshows/slideshows-gallery-intro.png" />
<div class="legend">
<ol class="arabic simple">
<li>View name: Gallery</li>
<li>Show content of type Gallery sorted by Newest first</li>
<li>[] Uncheck Page</li>
<li>[√] Check Block</li>
<li>Block title: Gallery</li>
<li>Display format: Slideshow of fields</li>
<li>Items per page: (Make this blank)</li>
<li>Continue &amp; Edit</li>
</ol>
</div>
</div>
<div class="figure">
<img alt="An image of the Main Views Interface" src="sites/default/files/recipes/slideshows/slideshows-gallery.png" />
<p class="caption">In main Views interface, we&#8217;ll configure three areas:</p>
<div class="legend">
<div class="line-block">
<div class="line">A) Fields</div>
<div class="line">B) Format</div>
<div class="line">C) Advanced: Contextual filters</div>
</div>
<p>We’ll set them up in this order because they depend upon each other, even though they’re visually in a different order.</p>
</div>
</div>
</div>
<div class="section" id="a-fields">
<h3>4.1.2. A. Fields</h3>
<div class="section" id="add-the-main-gallery-image">
<h4>Add the main gallery image</h4>
<a href="http://www.youtube.com/v/XKXVWo0_uaI?fs=1" class="recipe-step colorbox-load" title="Watch this step">Watch</a><ol class="arabic simple">
<li>add: Content: Gallery image</li>
<li>[ ] Create a label &lt;- Uncheck this</li>
<li>Image style: gallery_main.</li>
<li>Multiple Field Settings: [ ] Display all values in the same row &lt;- Uncheck this</li>
<li>Apply (All displays)</li>
</ol>
</div>
<div class="section" id="add-the-thumbnail-gallery-images">
<h4>Add the thumbnail gallery images</h4>
<a href="http://www.youtube.com/v/WNsXVJ8Z_FY" class="recipe-step" title="Watch this step">Watch</a><ol class="arabic simple">
<li>add &gt; Content: Gallery image</li>
<li>[ ] Create a label &lt;- Remove check</li>
<li>[√] Exclude from display &lt;- Check this</li>
<li>Image style: gallery_thumb.</li>
<li>Multiple Field Settings: [ ] Display all values in the same row &lt;- Uncheck this</li>
<li>Apply (All displays)</li>
</ol>
</div>
<div class="section" id="add-the-alt-text">
<h4>Add the Alt text</h4>
<a href="http://www.youtube.com/v/HHqg_3v9x2A?fs=1" class="recipe-step" title="Watch this step">Watch</a><ol class="arabic simple">
<li>add &gt; Content: Gallery image</li>
<li>[ ] Create a label &lt;- Uncheck this</li>
<li>Leave other visible settings at their default</li>
<li>Multiple Field Settings: [ ] Display all values in the same row &lt;- Uncheck this</li>
<li>Expand Rewrite Results</li>
<li>[√] Rewrite the output of this field &lt;- Check this</li>
<li>In the text field, enter [field_gallery_image_2-alt] &lt;- View the available patterns by expanding Replacement Patterns.)</li>
<li>Apply (all displays)</li>
</ol>
<p>You now have three fields, all named the same thing but configured differently: the main image, the thumbnails, and the text.</p>
</div>
<div class="section" id="remove-the-title">
<h4>Remove the title</h4>
<ol class="arabic simple">
<li>Content: Title &lt;- Click the words</li>
<li>Scroll and click Remove</li>
</ol>
</div>
</div>
<div class="section" id="b-format">
<h3>4.1.3. B. Format</h3>
<a href="http://www.youtube.com/v/hntqtWq3fH4?fs=1" class="recipe-step" title="Watch this step">Watch</a><ol class="arabic simple">
<li>Format: Settings</li>
<li>In the Top Widgets section, check Controls.</li>
<li>In the Bottom Widgets section, check Pager and choose the middle instance of Content: Gallery Image. This will provide the thumbnail images for the pager.</li>
<li>Apply (All displays)</li>
</ol>
</div>
<div class="section" id="c-advanced-contextual-filter">
<h3>4.1.4. C. Advanced: Contextual filter</h3>
<a href="http://www.youtube.com/v/KmnDpv8vWKg" class="recipe-step" title="Watch this step">Watch</a><ol class="arabic simple">
<li>add &gt; Content: Nid</li>
</ol>
<p>#. (∙) Provide a default value
#  [√] Type: Content ID from URL
#. Apply (All displays)</p>
<p>Be sure to save the view!</p>
</div>
</div>
<div class="section" id="place-and-configure-the-block">
<h2>4.2. Place and configure the block</h2>
<p><em>Structure &gt; Blocks &gt; Views: Galleries &gt; Configure</em></p>
<p>Configuring the block to display only on Gallery nodes prevents it from being called on a view, and listing it only on specific pages prevents it from appearing on the Edit tab.</p>
<ol class="arabic simple">
<li>Block title:  &lt;none&gt;</li>
<li>Footheme (default theme): Content &lt;- Select from drop-down</li>
<li>Save block</li>
</ol>
<p><strong>Visibility Settings</strong></p>
<table border="1" class="docutils">
<colgroup>
<col width="30%" />
<col width="70%" />
</colgroup>
<tbody valign="top">
<tr class="row-odd"><td>Pages</td>
<td>(∙) Only the listed pages
galleries*</td>
</tr>
<tr class="row-even"><td>Content types</td>
<td>[√] Gallery (Check only this option)</td>
</tr>
<tr class="row-odd"><td>Roles</td>
<td>(Leave as is)</td>
</tr>
<tr class="row-even"><td colspan="2">Users              (Leave as is)</td>
</tr>
</tbody>
</table>
</div>
</div>
<div class="section" id="create-an-index-of-all-galleries">
<h1>5. Create an index of all galleries</h1>
<p><em>Structure &gt; Views &gt; +Add new view</em></p>
<p>You could create the gallery index page in the same view as the gallery block by adding a Page display, but the settings are different enough that they don’t gain a lot by sharing defaults, so we’ll create this as a separate view.</p>
<div class="section" id="add-a-new-view">
<h2>5.1. Add a new view</h2>
<a href="http://www.youtube.com/v/8RJ0l4juOZY?fs=1" class="recipe-step" title="Watch this step">Watch</a><div class="section" id="intro-screen">
<h3>5.1.1. Intro screen</h3>
<ol class="arabic simple">
<li>View name: Galleries</li>
<li>Show Content of type Gallery sorted by Newest first</li>
<li>[√] Create a page</li>
<li>Page title: Galleries</li>
<li>Display format: Grid of fields</li>
<li>Items to display: 24</li>
<li>[√] Create a menu link &gt; Menu: Main menu</li>
<li>Link text: Galleries</li>
<li>Continue &amp; edit</li>
</ol>
</div>
<div class="section" id="fields">
<h3>5.1.2. Fields</h3>
<a href="http://www.youtube.com/v/4FynfGen1qI" class="recipe-step" title="Watch this step">Watch</a><ol class="arabic simple">
<li>add</li>
<li>For: All displays</li>
<li>[√] Content: Gallery image</li>
<li>[ ] Create a label</li>
<li>Formatter: Image (no change)</li>
<li>Image style: gallery_index</li>
<li>Link image to: Content</li>
<li>Multiple Field Settings: Accept defaults EXCEPT change Display all value(s) so it reads Display 1 value(s)</li>
<li>Apply (all displays)</li>
<li>Save the view</li>
</ol>
</div>
</div>
<div class="section" id="a-brief-detour">
<h2>5.2. A brief detour</h2>
<p>Some themes, like Bartik, have the Main Menu placed in the theme&#8217;s code. Others, like Sky and our sub-theme of Sky, use the block system to place the main menu.</p>
<p>Because we haven&#8217;t placed the Main menu in a region, we can&#8217;t see if our new view is appearing properly in the menu.</p>
<div class="section" id="place-the-main-menu-block">
<h3>5.2.1. Place the Main Menu block</h3>
<p><em>Structure &gt; Blocks &gt; Main menu: configure</em></p>
<p>Footheme uses the block system to place menus, and the main menu is not enabled yet.</p>
<p>After you&#8217;ve located the Main menu block and clicked configure, under the Region Settings:</p>
<ol class="arabic simple">
<li>For Footheme (default theme), select Menu Bar.</li>
<li>Save block</li>
<li>Verify the menu and galleries link are visible by visiting the home page.</li>
</ol>
</div>
<div class="section" id="arrange-the-menu-links">
<h3>5.2.2. Arrange the menu links</h3>
<p><em>Structure &gt; Menus &gt; Main Menu: edit links</em></p>
<p>Now that you can see the main menu, you&#8217;ll probably want to rearrange the links so that the Home link is left-most.</p>
<ol class="arabic simple">
<li>Use the grabber to drag Home to the top of the menu.</li>
</ol>
</div>
</div>
<div class="section" id="auto-generate-galleries">
<h2>5.3. Auto-generate galleries</h2>
<p><em>Configuration &gt; Development: Generate content</em></p>
<ol class="arabic simple">
<li>[√] Gallery (Uncheck others)</li>
<li>Accept the rest of the defaults</li>
<li>Generate</li>
</ol>
<p>When you&#8217;re done, visit your gallery index page to see what it looks like when it&#8217;s populated.</p>
</div>
</div>
<div class="section" id="style-the-gallery">
<h1>6. Style the Gallery</h1>
<div class="figure">
<img alt="Arrange the thumbnails." src="sites/default/files/recipes/slideshows/slideshows-before-theming.png" />
<div class="legend">
<p>We&#8217;re nearly there. The thumbnails present and you can click them to change the image, but they are taking up way too much screen real estate. We have text controls, but they kind of run together. There&#8217;s text, but it&#8217;s below our main image.</p>
<p>To solve these issues, we will edit the our custom theme&#8217;s css file to style the gallery.</p>
</div>
</div>
<div class="section" id="open-footheme-css">
<h2>6.1. Open footheme.css</h2>
<p>You can edit your stylesheet any way that is comfortable for you. If you need more support connecting than the username and password for your sandbox, see Connecting to your sandbox with sFTP at <a class="reference external" href="http://training.opensourcery.com/basics/sftp">http://training.opensourcery.com/basics/sftp</a></p>
<p>Open sites/all/modules/footheme/css/footheme.css  If you&#8217;re connecting to a sandbox, it will be located inside of www/drupal. You&#8217;ll find comments at the top, but it&#8217;s otherwise empty. Place the CSS for each step at the bottom of this file, save, and reload a gallery page to see the changes.</p>
</div>
<div class="section" id="arrange-thumbnails-beneath-the-main-image">
<h2>6.2. Arrange thumbnails beneath the main image</h2>
<div class="figure">
<img alt="The slideshow before theming." src="sites/default/files/recipes/slideshows/slideshows-thumbnails-arranged.png" />
<div class="legend">
<p>First, we&#8217;ll float the thumbnails horizontally and ensure that they don&#8217;t extend past the edge of the main photo.</p>
<div class="highlight-python"><pre>/* Arrange the thumbnails beneath the main image */
.views-content-field-gallery-image {
  float: left;
  padding-right: 13px;
}

.views-slideshow-cycle-main-frame-row-item {
  padding: 5px 20px;
}

.views-slideshow-controls-bottom {
  padding: 0 0 0 20px;
  width: 680px;
}</pre>
</div>
</div>
</div>
</div>
<div class="section" id="format-the-controls">
<h2>6.3. Format the controls</h2>
<div class="figure">
<img alt="The slideshow before theming." src="sites/default/files/recipes/slideshows/slideshows-controls-formatted.png" />
<div class="legend">
<p>If you mouse over the Pause link on the slideshow in your sandbox (not the image here!), you&#8217;ll see the text hop around. That&#8217;s because both words are given the same space but they&#8217;re not the same size. We&#8217;ll make room for Resume and add separators with the CSS below.</p>
<div class="highlight-python"><pre>/* Format the controls */
.views-slideshow-controls-text {
  padding-left: 20px;
}

.views-slideshow-controls-text span {
  display:  block;
  float: left;
}

.views_slideshow_controls_text_resume,
.views_slideshow_controls_text_pause{
  text-align: center;
  width: 55px;
  border-left: 1px solid #ccc;
  border-right: 1px solid #ccc;
  padding: 0 5px;
  margin: 0 5px;
}</pre>
</div>
</div>
</div>
</div>
<div class="section" id="place-alt-text-over-the-main-image">
<h2>6.4. Place alt text over the main image</h2>
<p><em>Structure &gt; Views &gt; Gallery: edit</em></p>
<div class="figure">
<img alt="The text overlay." src="sites/default/files/recipes/slideshows/slideshows-text-overlay.png" />
<div class="legend">
<p>Notice that we use background, not background color, and that we&#8217;re defining it twice. The first uses rgb as a fallback to provide a background color to browsers that don&#8217;t support the alpha transparency in the next. We&#8217;re also using background rather than background-color to ensure that a background is present in Internet Explorer. For a full discussion of this technique, see <a class="reference external" href="http://css-tricks.com/rgba-browser-support/">http://css-tricks.com/rgba-browser-support/</a></p>
<ol class="arabic simple">
<li>Add the styling to footheme.css:</li>
</ol>
<div class="highlight-python"><pre> /* Overlay the text on the main image */
 .views-field-field-gallery-image {
   position: relative;
 }

.views-field-field-gallery-image-2 div.field-content {
  position: absolute;
  bottom: -10px;
  left: 0px;
  width: 610px;
  height: 45px;
  margin: 20px;
  padding: 15px;
  color: #FFF;
  background: rgb(10,10,10);
  background: rgba(10,10,10,.7);
}</pre>
</div>
</div>
</div>
</div>
</div>
<div class="section" id="set-and-test-permissions">
<h1>7. Set and test permissions</h1>
<p><em>People &gt; Permissions</em></p>
<p>If you are not using the Test Kitchen Install Profile or if you are new to the idea of users, roles, permissions or masquerade, see <a class="reference external" href="http://training.opensourcery.com/basics">http://training.opensourcery.com/basics</a></p>
<div class="section" id="set-permissions">
<h2>7.1. Set permissions</h2>
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
<tr class="row-even"><td>Gallery: Create new content</td>
<td>[√]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
<tr class="row-odd"><td>Gallery: Edit own content</td>
<td>[√]</td>
<td>[ ]</td>
<td>[√]</td>
</tr>
<tr class="row-even"><td>Gallery: Edit any content</td>
<td>[ ]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
<tr class="row-odd"><td>Gallery: Delete own content</td>
<td>[√]</td>
<td>[ ]</td>
<td>[√]</td>
</tr>
<tr class="row-even"><td>Gallery: Delete any content</td>
<td>[ ]</td>
<td>[√]</td>
<td>[√]</td>
</tr>
</tbody>
</table>
</div>
<div class="section" id="test-author-privileges">
<h2>7.2. Test Author privileges</h2>
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
<h2>7.3. Test Editor privileges</h2>
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
      