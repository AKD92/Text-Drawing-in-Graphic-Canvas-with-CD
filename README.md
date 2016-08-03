
<p>
<h1>
Rendering Text Data on Canvas with CD Toolkit
</h1>
<h3><i>
A direct approach...
</i></h3>
</p>

<p>
<b>
<ul>
<li>
The famous & widely used <i>OpenGL</i> graphics library lacks direct support for rendering Text.
</li>
<li>
So how can we <i>RENDER TEXT & CHARACTERS ??</i>
</li>
<li>
The solution to the problem would be simpler if we use <i>CD</i> toolkit.
</li>
</ul>
</b>
</p>


<img src="/res/Text_Draw_CD_SCR1.png" alt="Text Drawing with CD" align="right">

<p align="justify">
<b>Canvas Draw (CD)</b> is a <i>vector graphics toolkit</i> with <i>device independent output</i>. Developed by a Brazilian software company <b>Tecgraf/PUC-Rio</b>, CD has the ability to draw text as well as graphic primitives. It is implemented in several platforms using native graphics support: <i>Microsoft Windows (GDI)</i> and <i>X-Windows (XLIB)</i>.
</p>

<p align="justify">
For text drawing, CD internally uses <b>FreeType</b>, an open-source and efficient font rendering engine.
</p>

<p align="justify">
CD contains functions to support <b>both vector and raster image applications</b>, and the visualization surface can be either a window or a more abstract surface, such as Image, Clipboard, Metafile, PS, and so on.
</p>

<p align="justify">
This is a simple demonstration on how to draw <b>Ascii Characters & Text</b> as well as other graphic elements on the canvas using CD.
</p>

<h3>Download This Demo</h3>
<ul>
<li><b>
<a href="https://github.com/AKD92/Text-Rendering-on-Graphic-Canvas-with-CD/raw/master/bin/iup_cd_text_draw_demo.exe">
Binary Executable</a> (Compiled using <a href="http://tdm-gcc.tdragon.net/about">TDM-GCC 5.1</a>)
</b></li>
<li><b>
<a href="/src">Browse for Source Codes in C</a> on GitHub
</b></li>
</ul>

<h3>Related Links</h3>
<ul>
<li><b>
<a href="http://webserver2.tecgraf.puc-rio.br/ftp_pub/lfm/cd.pdf">CD Toolkit Overview</a>
</b></li>
<li><b>
<a href="https://webserver2.tecgraf.puc-rio.br/cd/">Canvas Draw (CD) Home Page</a>
</b></li>
<li><b>
<a href="http://learnopengl.com/#!In-Practice/Text-Rendering">
Indirect Approach to Rendering Text with OpenGL & FreeType</a>
</b></li>
<li><b>
<a href="https://www.freetype.org/">The FreeType Project Home Page</a>
</b></li>
</ul>
