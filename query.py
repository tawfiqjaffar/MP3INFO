#!/usr/bin/env python3

from bs4 import BeautifulSoup as bs
from urllib.request import urlopen, urlretrieve
from pathlib import Path

url = 'http://mp3pn.info/search/s/f/'


def main(query):
    url = getSearchResults(query)
    download(url)


def getSearchResults(query):
    query_to_url = url + query.replace(' ', '+') + '/'
    query_opened = urlopen(query_to_url)
    html = bs(query_opened, "html.parser")
    d = {}

    artists = html.findAll("i", {"class": "cplayer-data-sound-author"})
    songs = html.findAll("b", {"class": "cplayer-data-sound-title"})
    print(len(songs))
    print(len(artists))
    for i in range(len(songs)):
        if i != 0 and i % 10 == 0:
            print('Show 10 more?(y/n)')
            response = input()
            if response == 'n':
                break

        a = str(artists[i])
        a = a[37:][:-4]
        id_url = str(artists[i].find_next())[15:]
        id_tag = ''
        for c in id_url:
            if c != '/':
                id_tag += c
            else:
                break

        result = html.findAll("li", {"data-sound-id": id_tag})
        print()
        download_url = result[0]['data-download-url']
        print(str(i + 1) + ' - ' + a)
        s = str(songs[i])
        s = s[36:][:-4].replace('&amp;', '&')
        d[str(i + 1)] = (download_url, "{} - {}.mp3".format(a, s))
        print('\t{}'.format(s))
        print()

    print('END.')
    print()
    print('Item to download: ')
    item = input()

    return d[item]


def download(url):
    found = False
    while found is False:
        print()
        print()
        print('Destination directory: ')
        destination = input()
        print()
        destination = destination.replace("~/", str(Path.home()) + '/')
        if destination[len(destination) - 1] != '/':
            destination += '/'
        print()
        try:
            print('DOWNLOADING')
            print()
            urlretrieve(url[0], destination + url[1])
            print ("DOWNLOADED")

            print('\t--> {}'.format(destination + url[1]))
            found = True
        except FileNotFoundError:
            print('Destination not found.\nDoes directory {} exist?'.format(destination))
