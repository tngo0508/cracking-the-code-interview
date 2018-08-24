from LinkedList import LinkedList


def remove_dups(ll):
    if ll.head is None:
        return

    curr = ll.head
    seen = set([curr.value])
    while curr.next:
        if curr.next.value in seen:
            curr.next = curr.next.next
        else:
            seen.add(curr.next.value)
            curr = curr.next

    return ll


def remove_dups_followup(ll):
    if ll.head is None:
        return

    curr = ll.head
    while curr:
        runner = curr
        while runner.next:
            if runner.next.value == curr.value:
                runner.next = runner.next.next
            else:
                runner = runner.next
        curr = curr.next

    return ll.head


ll = LinkedList()
ll.generate(100, 0, 9)
print(ll)
remove_dups(ll)
print(ll)

ll.generate(100, 0, 9)
print(ll)
remove_dups_followup(ll)
print(ll)
