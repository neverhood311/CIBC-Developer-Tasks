/*
	Dependency Graph Generator
	Justin Jensen
	11/16/17
*/

//make a list of nodes
var a = {name:'a', dependsOn:[], tempMark:false, permMark:false};
var b = {name:'b', dependsOn:[], tempMark:false, permMark:false};
var c = {name:'c', dependsOn:[], tempMark:false, permMark:false};
var d = {name:'d', dependsOn:[], tempMark:false, permMark:false};
var e = {name:'e', dependsOn:[], tempMark:false, permMark:false};
var f = {name:'f', dependsOn:[], tempMark:false, permMark:false};


//add some dependencies
d.dependsOn.push(a);
b.dependsOn.push(f);
d.dependsOn.push(b);
a.dependsOn.push(f);
c.dependsOn.push(d);
//a.dependsOn.push(c);	//uncomment to add a cycle

var allNodes = [a,b,c,d,e,f];


function depOrder(allNodes){
	let sortedNodes = [];
	let numUnmarked = allNodes.length;
	let nonDAG = false;
	while(numUnmarked > 0){
		let nextNode = undefined;
		//get the next unmarked node
		for(let i = 0; i < allNodes.length; i++){
			let node = allNodes[i];
			if(!node.tempMark && !node.permMark){
				nextNode = node;
				break;
			}
		}
		//visit it
		let result = visit(nextNode, sortedNodes);
		if(result == true)
			return "ERROR!!";	//we found a cycle
		
		//count the number unmarked
		numUnmarked = 0;
		for(let i = 0; i < allNodes.length; i++){
			let node = allNodes[i];
			if(!node.tempMark && !node.permMark){
				numUnmarked++;
			}
		}
	}
	
	//if you made it here, then you have a proper DAG
	return sortedNodes.reverse();
}

function visit(node, sortedNodes){
	//if node has a permanent mark, then return false
	if(node.permMark)
		return false;	//this one's already taken care of
	//if node has a temporary mark, then return true (error)
	if(node.tempMark)
		return true;	//we've found a cycle!!!
	//mark node temporarily
	node.tempMark = true;
	//for each of node's dependencies
	for(let i = 0; i < node.dependsOn.length; i++){
		//visit the dependency
		let result = visit(node.dependsOn[i], sortedNodes);
		if(result == true)
			return true;	//another node found a circular dependency!!
	}
	//mark node permanently
	node.permMark = true;
	//add node to the head of sortedNodes
	sortedNodes.unshift(node);
	return false;	//haven't found a cycle yet
}