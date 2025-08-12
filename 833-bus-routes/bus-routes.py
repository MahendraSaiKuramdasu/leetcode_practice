from queue import Queue

class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        stop_bus = defaultdict(list)
        vis_bus = set()
        vis_stop = set()
        if target == source:
            return 0
        for i, route in enumerate(routes):
            for j in route:
                stop_bus[j].append(i)

        q = Queue()
        q.put(source)
        vis_stop.add(source)
        cnt = 0
        while q.qsize() > 0:
            qn = q.qsize()
            while qn > 0:
                qn-=1
                stop = q.get()
                if stop == target:
                    return cnt
                for bus in stop_bus[stop]:
                    if bus not in vis_bus:
                        vis_bus.add(bus)
                        for r in routes[bus]:
                            if r not in vis_stop:
                                vis_stop.add(r)
                                q.put(r)
            cnt+=1

        return -1

