function ListNode(value){
    this.value = value;
    this.next = null;
};

function arrayToList(arr){
    if(!arr){
        return null;
    }
    let head = null, tail = null;
    arr.forEach( e =>{
        let node =  new ListNode(e);
        if(head == null){
            head = node;
        }else{
            tail.next = node;
        }
        tail = node;
    });
    return head;
}

function printList(list){
    let head = list;
    while(head != null){
        console.log(head.value);
        head = head.next;
    }
}

printList(arrayToList([3,4,2,3,1,3,0]));

