#!/usr/bin/env python
import os
begin = '<div class="document">'
end = '<div class="clearer">'

cwd = os.path.split(os.getcwd())[1]


with open('_build/html/%s.html' % cwd) as f:
    html =  f.read()
    header = html.split(begin)
    footer = header[1].split(end)
    body = footer[0]

with open('_build/html/%s.inc' % cwd, 'w') as f:
    f.write(body)

with open('/var/www/training/docroot/sites/all/sphinx/%s.inc' % cwd, 'w') as f:
    f.write(body)
