
      <div class="documentwrapper">
          <div class="body">
            
  <div class="section" id="project-set-up-steps">
<h1>1. Project Set Up Steps</h1>
<ol class="arabic simple">
<li>cp -r template projectname</li>
<li>vi projectname/conf.py</li>
<li>:%s/Template/Project Name/</li>
<li>:%s/template/projectname/</li>
<li>vi projectname/index.txt &lt;- change the project name to the proper filename, e.g., exactly what you named the project folder.  This is required for the stripping script to work.</li>
<li>mv template.txt projectname.txt</li>
</ol>
<div class="section" id="about-the-setup">
<h2>1.1. About the setup</h2>
<p>In order to make the output of Sphinx line up with Drupal, we have the following structure:</p>
<ol class="arabic simple">
<li>Actual image files are located in Sphinx/sites/default/files/recipes</li>
<li>This is sym_linked inside of Sphinx/_static which has the actual stylesheets we&#8217;re using. sites -&gt; ../sites</li>
<li>Sphinx/_static is a symlink inside each project: _static -&gt; ../_static. This is created by copying the template.</li>
<li>strip_header.py is located in Sphinx and symlinked inside the projects: strip_header.py -&gt; ../strip_header.py</li>
<li>the _build/html folder has a symlink to the sites folder, too, so that the images will actually load. This, too, is created by copying the template file.  sites -&gt; ../../../sites</li>
<li>There&#8217;s a substitution at the beginning of each file, |sandbox-setup| that is stored in the conf.py, which in turn pulls from the master symlink. To update this text for every project, edit the Sphinx/global.inc file. Presumably this will be used for other global substitutions in the future.</li>
</ol>
<div class="section" id="working-on-the-project">
<h3>1.1.1. Working on the Project</h3>
<ol class="arabic simple">
<li>Document written steps.</li>
<li>Minimal screen captures.</li>
</ol>
</div>
</div>
</div>


          </div>
      </div>
      