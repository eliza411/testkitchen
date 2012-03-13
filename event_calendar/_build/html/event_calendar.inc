
      <div class="documentwrapper">
          <div class="body">
            
  <div class="no-break section" id="ingredients">
<h1>1. Ingredients</h1>
<p>Test kitchen recipes are based on our sandbox setup, which includes pre-installed modules used every time. See <a class="reference external" href="http://training.opensourcery.com/sandbox/setup">http://training.opensourcery.com/sandbox/setup</a> to configure your own environment to match these instructions.</p>
<div class="section" id="staple">
<h2>1.1. Staple</h2>
<ol class="arabic simple">
<li><a class="reference external" href="http://drupal.org/project/ctools">http://drupal.org/project/ctools</a> - Enable Chaos tools</li>
<li><a class="reference external" href="http://drupal.org/project/views">http://drupal.org/project/views</a> - Views: Enable Views and Views UI</li>
<li><a class="reference external" href="http://drupal.org/project/date">http://drupal.org/project/date</a> - Date: Enable Date, Date API, Date Repeat, Date Popup</li>
<li><a class="reference external" href="http://drupal.org/project/fullcalendar">http://drupal.org/project/fullcalendar</a> - FullCalendar: Enable FullCalendar, FullCalendar Colors</li>
<li><a class="reference external" href="http://drupal.org/project/colors">http://drupal.org/project/colors</a> API - Other: Enable Colors (install the dev version)</li>
<li><a class="reference external" href="http://drupal.org/project/colorbox">http://drupal.org/project/colorbox</a> - Other: Enable Colorbox</li>
</ol>
<p><strong>Drush users:</strong></p>
<div class="highlight-python"><pre>drush dl ctools views date date_api fullcalendar fullcalendar_colors colors colorbox
drush en ctools views views_ui date date_api date_repeat date_popup
fullcalendar fullcalendar_colors colors colorbox -y</pre>
</div>
</div>
<div class="section" id="specialty">
<h2>1.2. Specialty</h2>
<p>FullCalendar JQuery Libraries</p>
<ol class="arabic simple">
<li>Visit <a class="reference external" href="http://arshaw.com/fullcalendar">http://arshaw.com/fullcalendar</a></li>
<li>Download the most recent version of the plugin.</li>
<li>Unzip to sites/all/libraries/fullcalendar (e.g., sites/all/libraries/fullcalendar/fullcalendar.min.js).  &lt;- Note: the fullcalendar directory is inside another fullcalendar-1.5.x.</li>
<li>Do not include the demos or jQuery directories.</li>
</ol>
<p class="page-break">ColorBox Library</p>
<ol class="arabic simple">
<li>Visit <a class="reference external" href="http://jacklmoore.com/colorbox/">http://jacklmoore.com/colorbox/</a></li>
<li>Download Current version</li>
<li>Unzip it straight into sites/all/libraries (e.g., sites/all/libraries/colorbox)</li>
</ol>
</div>
</div>
<div class="no-break section" id="build-a-way-to-create-events">
<h1>2. Build a way to create events</h1>
<div class="section" id="add-a-new-content-type-called-event">
<h2>2.1. Add a new content type called Event</h2>
<p><em>Structure &gt; Content types &gt; +Add new content type</em></p>
<p>Name: Event</p>
<p>Description: Create an event for display on the site calendar</p>
<table border="1" class="docutils">
<colgroup>
<col width="42%" />
<col width="58%" />
</colgroup>
<tbody valign="top">
<tr class="row-odd"><td>Submission Form Settings</td>
<td>Title field label: Event</td>
</tr>
<tr class="row-even"><td>Publishing Options</td>
<td>[√] Published  uncheck others</td>
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
</div>
<div class="section" id="configure-region-and-language-settings">
<h2>2.2. Configure Region and Language Settings</h2>
<p><em>Configuration &gt; Regional and language &gt; Regional settings</em></p>
<div class="note-error container">
The configuration and status pages will show warnings and display instructions for initially configuring Date module.</div>
<p><strong>Locale</strong></p>
<ol class="arabic simple">
<li>Default country: United States</li>
<li>First day of the week: Sunday</li>
<li>[ ] Use ISO-8601 week numbers &lt;- Leave unchecked</li>
</ol>
<p><strong>Time Zones</strong></p>
<p>For this recipe, the calendar represents events happening in a single geographical location, so we won&#8217;t be using timezone settings.</p>
<ol class="arabic simple">
<li>Default time zone: America/Los Angeles</li>
<li>[ ] Users may set their own timezones &lt;- Uncheck this</li>
</ol>
</div>
<div class="page-break section" id="configure-date-and-time">
<h2>2.3. Configure Date and Time</h2>
<p><em>Configuration &gt; Regional and language &gt; Date and time</em></p>
<p>Initial Date Module Configuration</p>
<ol class="arabic simple">
<li>Select formats for Long, Medium, or Short &lt;- Accept the defaults</li>
<li>Click Save configuration. This provides the initial configuration for the date module and removes the warning on the modules page.</li>
</ol>
<p>Add a new date format</p>
<ol class="arabic simple">
<li>Choose the Formats tab &lt;- upper right</li>
<li>+Add format</li>
<li>Format string: d M Y</li>
<li>Save with: Add format</li>
<li>Choose the Types tab &lt;-upper right</li>
<li>+Add date type</li>
<li>Date type: Block-short &lt;- this is just a label, you can choose any convention you like.</li>
<li>Date format: Choose the example of the new format from the bottom of the select list: 14 Nov 2011</li>
</ol>
<div class="tip container">
Note: If you make a mistake with the format but don&#8217;t notice until later, you can edit a date format by returning to <em>Configuration &gt; Regional and Language: Date and Time &gt; Formats</em> and clicking the edit link for the format in question. Unfortuantely this will cause the format to be unassigned from its Date type. Visit the Types tab and re-select the format from the dropdown list where appropriate.  If you forget this last step, the date field won&#8217;t be automatically updated throughout your site.</div>
</div>
<div class="section" id="add-a-date-field">
<h2>2.4. Add a date field</h2>
<p><em>Structure &gt; Content types &gt; Event &gt; Manage fields</em></p>
<div class="section" id="add-new-field">
<h3>2.4.1. Add new field</h3>
<ol class="arabic simple">
<li>Label: Date</li>
<li>Field name: date</li>
<li>Type of data to store: Date &lt;- plain Date, not the ISO or Unix format</li>
<li>Form element to edit the data: Popup calendar</li>
<li>Save</li>
</ol>
<div class="section" id="field-settings">
<h4>Field Settings</h4>
<ol class="arabic simple">
<li>Accept all default field settings EXCEPT:</li>
<li>[√] Collect an end date &lt;- Check this</li>
<li>Save field settings</li>
</ol>
</div>
<div class="section" id="event-settings">
<h4>Event Settings</h4>
<ol class="arabic simple">
<li>Accept all default field settings EXCEPT:</li>
<li>[√] Required field &lt;- Check this</li>
<li>Save settings</li>
</ol>
</div>
</div>
</div>
<div class="section" id="rearrange-the-items">
<h2>2.5. Rearrange the items</h2>
<p><em>Structure &gt; Content types &gt; Event &gt; Manage fields</em></p>
<p>Use the grabber to drag and drop the fields into order:</p>
<ol class="arabic simple">
<li>Event name</li>
<li>Date</li>
<li>Body</li>
<li>URL path settings &lt;- This appears only when the Pathauto module is installed.</li>
<li>Save</li>
</ol>
</div>
<div class="section" id="create-proper-paths">
<h2>2.6. Create proper paths</h2>
<p><em>Configuration &gt; Search and Metadata: URL aliases &gt; Patterns</em></p>
<p>Later on, we&#8217;ll be creating a landing page at /calendar, so we&#8217;re adding that to the path now.</p>
<ol class="arabic simple">
<li>Pattern for all Event paths: calendar/[node:title]</li>
<li>Save configuration</li>
</ol>
</div>
<div class="section" id="create-an-event">
<h2>2.7. Create an event</h2>
<p><em>Content &gt; +Add content</em></p>
<ol class="arabic simple">
<li>Add an event scheduled for today called Training</li>
<li>Check that the path is as you expected, e.g. yoursite.everydaydrupal.com/<strong>calendar/training</strong></li>
</ol>
</div>
</div>
<div class="section" id="create-the-calendar">
<h1>3. Create the calendar</h1>
<div class="section" id="add-a-calendar-view">
<h2>3.1. Add a calendar view</h2>
<p><em>Structure &gt; Views &gt; +Add new view</em></p>
<div class="section" id="intro-screen">
<h3>3.1.1. Intro Screen</h3>
<ol class="arabic simple">
<li>View name: Calendar</li>
<li>Show Content of type Event sorted by Unsorted</li>
<li>[√] Create a page</li>
<li>Page title: Calendar</li>
<li>Path: calendar</li>
<li>Display format: FullCalendar</li>
<li>Items to display: &lt;- Blank this out</li>
<li>[ ] Use pager</li>
<li>[√] Create menu link</li>
<li>Menu: Main menu</li>
<li>Link text: Event calendar</li>
<li>[√] Include an RSS feed</li>
<li>Feed path: calendar.xml</li>
<li>Continue &amp; edit</li>
</ol>
<div class="note-error container">
You&#8217;ll see an error message as soon as you&#8217;ve clicked Continue &amp; edit. You have to add the Date field from your event to the view for the calendar to function.</div>
</div>
<div class="section" id="fields">
<h3>3.1.2. Fields</h3>
<ol class="arabic simple">
<li>add</li>
<li>For: All displays</li>
<li>[√] Content: Date</li>
<li>Apply (all displays)</li>
<li>[ ] Create a label &lt;- Uncheck this</li>
<li>It&#8217;s your choice what you set in the other visible areas. Don&#8217;t change anything in the collapsed field groups.</li>
<li>Apply (All displays)</li>
</ol>
</div>
<div class="page-break section" id="advanced-other">
<h3>3.1.3. Advanced: Other</h3>
<div class="section" id="use-ajax">
<h4>Use AJAX</h4>
<ol class="arabic simple">
<li>Click No</li>
<li>For: All displays</li>
<li>(*) Yes</li>
<li>Apply (all displays)</li>
</ol>
<div class="important-tip container">
For the drag and drop functionality to work when you switch pages, you MUST expancd the Advanced fieldgroup and set Ajax to Yes.</div>
</div>
</div>
</div>
</div>
<div class="section" id="create-and-place-an-upcoming-events-block">
<h1>4. Create and place an Upcoming events block</h1>
<p>We&#8217;ll create an Upcoming events block for the front page and our calendar pages. We could build this in the same view as the calendar, but since it&#8217;s substantially different, we&#8217;ll create it in its own view.</p>
<div class="section" id="create-the-block">
<h2>4.1. Create the block</h2>
<p><em>Structure &gt; Views &gt; +Add new view</em></p>
<div class="section" id="id1">
<h3>4.1.1. Intro Screen</h3>
<ol class="arabic simple">
<li>View name: Upcoming events</li>
<li>Show Content of type Event sorted by Unsorted &lt;- Choosing Newest first here would sort by when the Event node was created, not when the event was scheduled.</li>
<li>[ ] Create a page</li>
<li>[√] Create a block</li>
<li>Display fomat: Unformatted list of fields</li>
<li>Continue &amp; Edit</li>
</ol>
</div>
<div class="section" id="id2">
<h3>4.1.2. Fields</h3>
<div class="section" id="add-the-date-field">
<h4>Add the date field</h4>
<ol class="arabic simple">
<li>add</li>
<li>Content: Date</li>
<li>[ ] Create a label &lt;- Uncheck this</li>
<li>[ ] Exclude from display &lt;- Leave unchecked</li>
<li>Formatter:</li>
<li>Date and time</li>
<li>Choose how users view dates and times: Block-short</li>
<li>Display: Both Start and End dates</li>
<li>Don&#8217;t change anything in the collapsed field groups.</li>
<li>Apply (All displays)</li>
</ol>
</div>
</div>
<div class="page-break section" id="filter-criteria">
<h3>4.1.3. Filter Criteria</h3>
<div class="section" id="filter-to-future-dates">
<h4>Filter to future dates</h4>
<p>I filter on the date an event ends so that it remains visible while it&#8217;s happening, allowing users to reference directions or other information quickly. You might choose to filter by the Start date if it better suits your needs.</p>
<ol class="arabic simple">
<li>add &gt; Content: Date - end date (field_date:value2)</li>
<li>Configure extra settings for filter criterion:</li>
<li>Accept the defaults. They won&#8217;t matter.</li>
<li>Configure filter criterion:</li>
<li>Operator:</li>
<li>Is greater than</li>
<li>Enter a relative date &lt;- Choose from the dropdown that says Select a Date</li>
<li>Relative date:</li>
<li>now</li>
<li>Apply (all displays)</li>
</ol>
</div>
</div>
<div class="section" id="sort-criteria">
<h3>4.1.4. Sort Criteria</h3>
<div class="section" id="sort-by-the-date-of-the-event">
<h4>Sort by the date of the event</h4>
<ol class="arabic simple">
<li>add</li>
<li>Content: Date start date (field_date)</li>
<li>Apply (all displays)</li>
<li>(*) Sort ascending &lt;- default</li>
<li>Apply (all displays)</li>
<li>Don&#8217;t forget to save the view, too!</li>
</ol>
</div>
</div>
</div>
<div class="section" id="place-the-block">
<h2>4.2. Place the block</h2>
<p><em>Structure &gt; Blocks &gt; Views: Upcoming Event &gt; Configure</em></p>
<ol class="arabic simple">
<li>Block title: Upcoming events</li>
<li>Region Settings: Bartik (default theme): Sidebar Second</li>
</ol>
<table border="1" class="docutils">
<colgroup>
<col width="33%" />
<col width="67%" />
</colgroup>
<thead valign="bottom">
<tr class="row-odd"><th class="head" colspan="2">Visibility Settings</th>
</tr>
</thead>
<tbody valign="top">
<tr class="row-even"><td>Pages</td>
<td><p class="first">(*) Only the listed pages</p>
<p>&lt;front&gt;</p>
<p class="last">calendar/*</p>
</td>
</tr>
<tr class="row-odd"><td>Content types</td>
<td>[√] Event</td>
</tr>
<tr class="row-even"><td>Roles</td>
<td>(Leave as is)</td>
</tr>
<tr class="row-odd"><td>Users</td>
<td>(Leave as is)</td>
</tr>
</tbody>
</table>
</div>
</div>
<div class="section" id="categorize-events-by-terms">
<h1>5. Categorize events by terms</h1>
<div class="section" id="create-the-vocabulary-and-add-terms-to-it">
<h2>5.1. Create the vocabulary and add terms to it</h2>
<p><em>Structure &gt; Taxonomy &gt; +Add vocabulary</em></p>
<div class="section" id="add-the-vocabulary">
<h3>5.1.1. Add the vocabulary</h3>
<ol class="arabic simple">
<li>Name: Event Type</li>
<li>Description: Categorize events by type.</li>
</ol>
</div>
<div class="section" id="add-terms-to-the-event-type-vocabulary">
<h3>5.1.2. Add terms to the Event Type vocabulary</h3>
<ol class="arabic simple">
<li>Event Type: add terms</li>
<li>Name: Public</li>
<li>Description: These events are open to the public</li>
<li>Save &lt;- we&#8217;re accepting the defaults</li>
<li>Name: Staff Meeting</li>
<li>Description: These meetings are required meetings for all staff.</li>
<li>Save &lt;- we&#8217;re accepting the defaults</li>
<li>Return to <em>Structure &gt; Taxonomy</em> and click list terms to review or reorder. &lt;- optional</li>
</ol>
</div>
</div>
<div class="section" id="add-the-term-to-the-event-content-type">
<h2>5.2. Add the term to the Event content type</h2>
<p><em>Structure &gt; Content Types &gt; Event &gt; Manage Fields</em></p>
<div class="section" id="id3">
<h3>5.2.1. Add new field</h3>
<ol class="arabic simple">
<li>Label: Add new field: Event type</li>
<li>Name: field_event_type</li>
<li>Field: Term reference</li>
<li>Widget: Select List</li>
<li>Save</li>
<li>Vocabulary: Event Types</li>
<li>Save field settings</li>
<li>Accept all the defaults</li>
<li>Save settings</li>
<li>Drag the Event Type term beneath the Event name.</li>
<li>Save</li>
</ol>
</div>
</div>
<div class="section" id="create-and-tag-events">
<h2>5.3. Create and tag events</h2>
<p><em>Content &gt; +Add Content</em></p>
<ol class="arabic simple">
<li>Create an event in the current month tagged Public</li>
<li>Create an event in the current month tagged Staff Meeting</li>
<li>Create an event in the current month and don&#8217;t tag it.</li>
</ol>
</div>
</div>
<div class="section" id="color-code-events">
<h1>6. Color code events</h1>
<p><em>Configuration &gt; User Interface: FullCalendar &gt; Colors (tab) &gt; Taxonomy (subtab)</em></p>
<p>You can color code your events by Node Type, Taxonomy, or User Role.</p>
<div class="section" id="set-the-default-color">
<h2>6.1. Set the default color</h2>
<ol class="arabic simple">
<li>Choose the color for events that aren&#8217;t labeled with a term.</li>
</ol>
</div>
<div class="section" id="set-the-colors-for-the-taxonomy-terms">
<h2>6.2. Set the colors for the taxonomy terms</h2>
<ol class="arabic simple">
<li>Expand Event Type.</li>
<li>[√] Enable this vocabulary</li>
<li>Use the color picker to assign different colors.</li>
<li>Save configuration</li>
</ol>
</div>
<div class="section" id="check-out-the-colors-try-dragging-try-dropping">
<h2>6.3. Check out the colors. Try dragging. Try dropping.</h2>
</div>
</div>
<div class="section" id="create-filters-based-on-your-categories">
<h1>7. Create filters based on your categories</h1>
<p>There are several ways to maintain a master calendar and then filter it so that you show only certain events.</p>
<p>First, we&#8217;ll add a filter to the main calendar so users can choose what to see.</p>
<div class="section" id="add-drop-down-filter-to-the-existing-calendar">
<h2>7.1. Add drop down filter to the existing calendar</h2>
<p><em>Structure &gt; Views</em></p>
<p>Locate your calendar on the main views page or use the contextual links while viewing it to edit.</p>
<div class="section" id="id4">
<h3>7.1.1. Filter Criteria</h3>
<ol class="arabic simple">
<li>add</li>
<li>For: This page (override)</li>
<li>[√] Content: Has taxonomy term</li>
<li>Apply (this display)</li>
<li>(*) Vocabulary: Event type</li>
<li>Selection type (*) Autocomplete</li>
<li>Apply and continue</li>
<li>[√] Expose this filter to visitors, to allow them to change it</li>
<li>Label: Choose a category</li>
<li>Apply (this display)</li>
</ol>
</div>
</div>
<div class="section" id="create-a-pre-filtered-option">
<h2>7.2. Create a pre-filtered option</h2>
<p>We&#8217;re going to filter the calendar so that it only shows one kind of event and the user cannot change this. Organizations with complex structures  may prefer to shield their users from the selection process and choose instead to place these calendars in department areas.</p>
<div class="section" id="page-details">
<h3>7.2.1. Page details</h3>
<ol class="arabic simple">
<li>Click the arrow to the right of view page.</li>
<li>Choose clone page</li>
</ol>
</div>
<div class="section" id="block-details">
<h3>7.2.2. Block details</h3>
<ol class="arabic simple">
<li>Display name: Filtered by Page</li>
<li>Apply</li>
</ol>
</div>
<div class="section" id="block-settings">
<h3>7.2.3. Block settings</h3>
<ol class="arabic simple">
<li>Click calendar</li>
<li>calendar/%</li>
<li>Apply</li>
</ol>
</div>
<div class="section" id="advanced-contextual-filters">
<h3>7.2.4. Advanced: Contextual Filters</h3>
<ol class="arabic simple">
<li>add</li>
<li>For: This page (override)</li>
<li>[√] Content: Has taxonomy term ID</li>
<li>Apply (this display)</li>
<li>When the filter value is NOT in the URL: (*) Provide default value</li>
<li>Type: Taxonomy term ID from URL &lt;- Choose from the select list.</li>
<li>[ ] Load default filter from term page &lt;- Uncheck this</li>
<li>Add (this display)</li>
</ol>
<div class="question container">
<p><strong>Why create a second display?</strong></p>
<p>You might wonder why we&#8217;ve created a second display instead of just adding the contextual filter to the first Page display and putting the % wildcard at the end of its Path.</p>
<p>The wildcard prevents putting the calendar on the menu, so we had a choice. We could add all of the calendar links to the menu manually and create a single display, or we can create the main display and duplicate it. I chose the second because I wanted the main calendar view to contain the drop down filter that I did not want to place on the other views.</p>
</div>
</div>
</div>
<div class="section" id="add-our-filtered-views-to-the-main-menu">
<h2>7.3. Add our filtered views to the main menu</h2>
<p><em>Structure &gt; Menus &gt; Main Menu &gt; add link</em></p>
<p>Because we&#8217;re working with a simple test site, we&#8217;ll add menu entries for our event types to the main menu. If you need to verify the taxonomy id of a term you can Structure &gt; Taxonomy &gt; Event Types, list terms, and the Term ID is visible in the URL of the edit link (taxonomy/term/#)</p>
<ol class="arabic simple">
<li>Menu link title: Public Events</li>
<li>Path: calendar/1</li>
<li>Save</li>
<li>+Add link</li>
<li>Menu link title: Staff Meetings</li>
<li>Path: calendar/2</li>
<li>Save</li>
</ol>
<p><strong>Using terms vs. term names:</strong> Term names are better, really, because they&#8217;re more memorable. If the name is changed, however, then all the links using the name have to be updated or redirects must be put into place.</p>
</div>
</div>
<div class="section" id="set-and-test-permissions">
<h1>8. Set and test permissions</h1>
<p><em>People &gt; Permissions</em></p>
<p>If you are not using the Test Kitchen Install Profile or if you are new to the idea of users, roles, permissions or masquerade, see <a class="reference external" href="http://training.opensourcery.com/basics">http://training.opensourcery.com/basics</a></p>
<div class="section" id="set-permissions">
<h2>8.1. Set permissions</h2>
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
<h2>8.2. Test Author privileges</h2>
<p>Masquerade as Test Author and ensure you CAN:</p>
<ol class="arabic simple">
<li>Create an Event</li>
<li>Edit that Event</li>
<li>Delete that Event</li>
</ol>
<p>Ensure you CANNOT:</p>
<ol class="arabic simple">
<li>Edit events you didn’t create</li>
<li>Delete events you didn’t create</li>
</ol>
<p>When you’re done, remember to Switch back</p>
</div>
<div class="section" id="test-editor-privileges">
<h2>8.3. Test Editor privileges</h2>
<p>Masquerade as Test Editor and ensure you CAN:</p>
<ol class="arabic simple">
<li>Create an Event</li>
<li>Edit that Event</li>
<li>Delete that Event</li>
<li>Edit an Event you didn’t create</li>
<li>Delete an Event you didn’t create</li>
</ol>
</div>
</div>


          </div>
      </div>
      