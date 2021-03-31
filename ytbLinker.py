# genera el código markdown para que se muestre un video en github
# idea de https://stackoverflow.com/questions/11804820/how-can-i-embed-a-youtube-video-on-github-wiki-pages
# usamos la imagen que youtube usa de portada, 
# creamos un enlace  markdown al video con una imagen como descripción
# [![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/YOUTUBE_VIDEO_ID_HERE/0.jpg)](https://www.youtube.com/watch?v=YOUTUBE_VIDEO_ID_HERE)

v = '0.2'

while True:
    texto = input("URL del video ó Markdown del enlace al vídeo (Enter para terminar): ")
    if len(texto) < 2:
        break
    if texto.count('['): # es markdown
        partes = texto.split(']')
        urlVideo = partes[1].replace('(','').replace(')','')
        descripcion = partes[0].replace('[','')
    else : # es una url del video
        urlVideo = texto
        descripcion = input("Descripcion: ")
        if not descripcion.startswith('Video: '):
            descripcion = 'Video: ' + descripcion
    
    if len(urlVideo) < 1:
        break
    
    # print(f'Video = ({urlVideo}) Descripcion = ({descripcion})')
    
    if urlVideo.count('=')>0:
        id = urlVideo.split("=")[1]
    else:
        frag = urlVideo.split('/')
        id = frag[len(frag)-1]
    # print(id)

    urlImagen='https://img.youtube.com/vi/{}/0.jpg'.format(id)
    # print(urlImagen)


    linkURLImagen = f'[![{descripcion}]({urlImagen})]({urlVideo})'
    print('\n'+linkURLImagen+'\n')
    linkURL = f'[{descripcion}]({urlVideo})'
    print(linkURL+'\n')

