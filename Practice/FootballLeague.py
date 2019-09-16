n = int(input())
for _ in range(n):
    stats = {}
    for _ in range(12):
       lt_name,lt_goals,_,rt_goals,rt_name = input().split(' ')

       lt_goals = int(lt_goals)
       rt_goals = int(rt_goals)

       if lt_name not in stats:
         stats[lt_name] = { "pt" : 0, "gd" : 0 }

       if rt_name not in stats:
         stats[rt_name] = { "pt" : 0, "gd" : 0 }

       if lt_goals > rt_goals:
           stats[lt_name]["pt"] += 3
       elif rt_goals > lt_goals :
           stats[rt_name]["pt"] += 3
       else:
           stats[lt_name]["pt"] += 1
           stats[rt_name]["pt"] += 1

       stats[lt_name]["gd"] += (lt_goals - rt_goals)
       stats[rt_name]["gd"] += (rt_goals - lt_goals)

    stats_keys = stats.keys()
    # sort by point then by goal difference
    stats_sorted = sorted(stats_keys, key=lambda team : (stats[team]["pt"], stats[team]["gd"]), reverse=True)       
    print(stats_sorted[0], stats_sorted[1])
