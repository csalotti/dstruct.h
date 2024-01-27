const dstruct = @cImport(@cInclude("dstruct.c"));
const std = @import("std");
const testing = std.testing;

test "Linked List create" {
    const llist: *dstruct.Llist = dstruct.Llist_init(@sizeOf(c_int));
    try testing.expect(@TypeOf(llist.*) == dstruct.Llist);
    try testing.expectEqual(llist.*.size, 0);
    try testing.expectEqual(llist.*.element_size, 4);
    try testing.expectEqual(llist.*.head, null);
}

test "Linked List append int values" {
    var llist: *dstruct.Llist = dstruct.Llist_init(@sizeOf(c_int));
    var values = [2]c_int{ 69, 42 };
    for (values) |value| {
        const v: *anyopaque = @constCast(&value);
        try testing.expect(dstruct.Llist_append(llist, v));
    }
    // dummy head
    const dummy_value: *anyopaque = @constCast(&@as(c_int, 0));
    var head: dstruct.Node = dstruct.Node_init(dummy_value, @sizeOf(c_int)).*;
    head.next = llist.*.head;
    for (values) |value| {
        head = head.next.*;
        var head_value: *c_int = @alignCast(@ptrCast(head.value));
        try testing.expectEqual(@as(c_int, value), head_value.*);
    }
}

test "Linked List append float values" {
    var llist: *dstruct.Llist = dstruct.Llist_init(@sizeOf(f32));
    var values = [2]f32{ 6.9, 4.2 };
    for (values) |value| {
        var v: *anyopaque = @constCast(&value);
        try testing.expect(dstruct.Llist_append(llist, v));
    }
    // dummy head
    var dummy_value: *anyopaque = @constCast(&@as(f32, 0));
    var head: dstruct.Node = dstruct.Node_init(dummy_value, @sizeOf(f32)).*;
    head.next = llist.*.head;
    for (values) |value| {
        head = head.next.*;
        var head_value: *f32 = @alignCast(@ptrCast(head.value));
        try testing.expectEqual(@as(f32, value), head_value.*);
    }
}
