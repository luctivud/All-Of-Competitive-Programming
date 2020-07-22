while True:
    try:
        line = input()
        http = 'http://'
        if http in line:
            ind = line.index(http)
            # print(ind, line, line[ind:])
            link = line[ind:]
            li = list(link.strip(http).split('/'))
            siteURL = li[0]
            siteName = siteURL.split('.')[-2]
            problem = li[-1]
            print("   - [{} : {}]({})".format(siteName, problem, link))
    except:
        break