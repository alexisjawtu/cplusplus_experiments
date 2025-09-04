# coding: utf-8
import pandas as pd
df = pd.DataFrame({
    'sku': ['a','a','a','a','b','b','b','b','c','c','c','c'],
    'week_nr': [1,2,3,4,1,2,3,4,1,2,3,4],
    'rbp_inb': [69,51,0,71,62,81,73,0,91,84,101,95]
    })
df = pd.DataFrame({
    'a': list(range(-4,6)),
    'b': list(range(2,12)),
    'c': list(range(5,15))
    })

df.loc[df['a'] > 3]
df.groupby('sku')['rbp_inb'].cumsum()
df['local_cum_rbp_inb'] = df.groupby('sku')['rbp_inb'].cumsum()
df.sort_values(['rbp_inb', 'local_cum_rbp_inb'], ascending=[True, False])
df.sort_values(['sku', 'week_nr'], ascending=[True, True])
s = {('945-12897-2506-101', 41), ('930-13700-2500-100', 48), ('900-9X745-A548-SF0', 24), ('935-26287-0070-000', 23)}
       
class Set(set):
    def __str__(self):
        s = set.__str__(self)
        s = s[4:-1]
        s = s.replace('), (','),\n (') + '\n'
        return s

s2 = Set({('945-12897-2506-101', 41), ('930-13700-2500-100', 48), ('900-9X745-A548-SF0', 24), ('935-26287-0070-000', 23)})
