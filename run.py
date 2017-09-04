#!/usr/bin/env python3

import argparse
import query

parser = argparse.ArgumentParser()

parser.add_argument(
    '-s', '--search', help="python3 run.py -s 'songOrArist'")
args = parser.parse_args()
query.main(args.search)
