#!/usr/bin/env python3

from bs4 import BeautifulSoup as bs
from urllib.request import urlopen

url = urlopen('http://mp3pn.info/search/s/f/the+weeknd/')
html = bs(url, "html.parser")


def main():
    artists = html.findAll("i", {"class": "cplayer-data-sound-author"})
    songs = html.findAll("b", {"class": "cplayer-data-sound-title"})
    print(len(songs))
    print(len(artists))
    for i in range(len(songs)):
        a = str(artists[i])
        a = a[37:][:-4]
        id_url = str(artists[i].find_next())[15:]
        id_tag = ''
        for c in id_url:
            if c != '/':
                id_tag += c
            else:
                break
        print(a)
        print(id_tag)
        s = str(songs[i])
        s = s[36:][:-4]
        print('\t{}'.format(s))
        print()
    # for artist in artists:
    #     temp = str(artist)
    #
    #     print(temp[37:][:-4])
    #     print()


if __name__ == '__main__':
    main()
