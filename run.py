#!/usr/bin/env python3
import subprocess
import argparse
import query


parser = argparse.ArgumentParser()

parser.add_argument(
    '-s', '--search', help="python3 run.py -s 'songOrArist'")

args = parser.parse_args()

if args.search is None:
    print('No argument provided. Killing process.')
else:
    query.main(args.search)

subprocess.call('deactivate')
