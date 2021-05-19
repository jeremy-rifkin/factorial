; Clang's rediculous vectorized factorial (trademark pending)
; https://godbolt.org/z/1Maxerjj1

define dso_local i32 @_Z9factoriali(i32 %0) local_unnamed_addr #0 !dbg !8 {
  call void @llvm.dbg.value(metadata i32 %0, metadata !14, metadata !DIExpression()), !dbg !15
  %2 = icmp eq i32 %0, 0, !dbg !16
  br i1 %2, label %74, label %3, !dbg !18

3:                                                ; preds = %1
  %4 = icmp ult i32 %0, 8, !dbg !18
  br i1 %4, label %65, label %5, !dbg !18

5:                                                ; preds = %3
  %6 = and i32 %0, -8, !dbg !18
  %7 = and i32 %0, 7, !dbg !18
  %8 = insertelement <4 x i32> poison, i32 %0, i32 0, !dbg !18
  %9 = shufflevector <4 x i32> %8, <4 x i32> poison, <4 x i32> zeroinitializer, !dbg !18
  %10 = add <4 x i32> %9, <i32 0, i32 -1, i32 -2, i32 -3>, !dbg !18
  %11 = add i32 %6, -8, !dbg !18
  %12 = lshr exact i32 %11, 3, !dbg !18
  %13 = add nuw nsw i32 %12, 1, !dbg !18
  %14 = and i32 %13, 3, !dbg !18
  %15 = icmp ult i32 %11, 24, !dbg !18
  br i1 %15, label %41, label %16, !dbg !18

16:                                               ; preds = %5
  %17 = and i32 %13, 1073741820, !dbg !18
  br label %18, !dbg !18

18:                                               ; preds = %18, %16
  %19 = phi <4 x i32> [ %10, %16 ], [ %38, %18 ]
  %20 = phi <4 x i32> [ <i32 1, i32 1, i32 1, i32 1>, %16 ], [ %36, %18 ]
  %21 = phi <4 x i32> [ <i32 1, i32 1, i32 1, i32 1>, %16 ], [ %37, %18 ]
  %22 = phi i32 [ %17, %16 ], [ %39, %18 ]
  %23 = add <4 x i32> %19, <i32 -4, i32 -4, i32 -4, i32 -4>
  %24 = mul <4 x i32> %19, %20, !dbg !19
  %25 = mul <4 x i32> %23, %21, !dbg !19
  %26 = add <4 x i32> %19, <i32 -8, i32 -8, i32 -8, i32 -8>
  %27 = add <4 x i32> %19, <i32 -12, i32 -12, i32 -12, i32 -12>
  %28 = mul <4 x i32> %26, %24, !dbg !19
  %29 = mul <4 x i32> %27, %25, !dbg !19
  %30 = add <4 x i32> %19, <i32 -16, i32 -16, i32 -16, i32 -16>
  %31 = add <4 x i32> %19, <i32 -20, i32 -20, i32 -20, i32 -20>
  %32 = mul <4 x i32> %30, %28, !dbg !19
  %33 = mul <4 x i32> %31, %29, !dbg !19
  %34 = add <4 x i32> %19, <i32 -24, i32 -24, i32 -24, i32 -24>
  %35 = add <4 x i32> %19, <i32 -28, i32 -28, i32 -28, i32 -28>
  %36 = mul <4 x i32> %34, %32, !dbg !19
  %37 = mul <4 x i32> %35, %33, !dbg !19
  %38 = add <4 x i32> %19, <i32 -32, i32 -32, i32 -32, i32 -32>
  %39 = add i32 %22, -4
  %40 = icmp eq i32 %39, 0
  br i1 %40, label %41, label %18, !llvm.loop !20

41:                                               ; preds = %18, %5
  %42 = phi <4 x i32> [ undef, %5 ], [ %36, %18 ]
  %43 = phi <4 x i32> [ undef, %5 ], [ %37, %18 ]
  %44 = phi <4 x i32> [ %10, %5 ], [ %38, %18 ]
  %45 = phi <4 x i32> [ <i32 1, i32 1, i32 1, i32 1>, %5 ], [ %36, %18 ]
  %46 = phi <4 x i32> [ <i32 1, i32 1, i32 1, i32 1>, %5 ], [ %37, %18 ]
  %47 = icmp eq i32 %14, 0
  br i1 %47, label %59, label %48

48:                                               ; preds = %41, %48
  %49 = phi <4 x i32> [ %56, %48 ], [ %44, %41 ]
  %50 = phi <4 x i32> [ %54, %48 ], [ %45, %41 ]
  %51 = phi <4 x i32> [ %55, %48 ], [ %46, %41 ]
  %52 = phi i32 [ %57, %48 ], [ %14, %41 ]
  %53 = add <4 x i32> %49, <i32 -4, i32 -4, i32 -4, i32 -4>
  %54 = mul <4 x i32> %49, %50, !dbg !19
  %55 = mul <4 x i32> %53, %51, !dbg !19
  %56 = add <4 x i32> %49, <i32 -8, i32 -8, i32 -8, i32 -8>
  %57 = add i32 %52, -1
  %58 = icmp eq i32 %57, 0
  br i1 %58, label %59, label %48, !llvm.loop !22

59:                                               ; preds = %48, %41
  %60 = phi <4 x i32> [ %42, %41 ], [ %54, %48 ], !dbg !19
  %61 = phi <4 x i32> [ %43, %41 ], [ %55, %48 ], !dbg !19
  %62 = mul <4 x i32> %61, %60, !dbg !18
  %63 = call i32 @llvm.vector.reduce.mul.v4i32(<4 x i32> %62), !dbg !18
  %64 = icmp eq i32 %6, %0, !dbg !18
  br i1 %64, label %74, label %65, !dbg !18

65:                                               ; preds = %3, %59
  %66 = phi i32 [ %0, %3 ], [ %7, %59 ]
  %67 = phi i32 [ 1, %3 ], [ %63, %59 ]
  br label %68, !dbg !18

68:                                               ; preds = %65, %68
  %69 = phi i32 [ %71, %68 ], [ %66, %65 ]
  %70 = phi i32 [ %72, %68 ], [ %67, %65 ]
  call void @llvm.dbg.value(metadata i32 %69, metadata !14, metadata !DIExpression()), !dbg !15
  %71 = add nsw i32 %69, -1, !dbg !24
  %72 = mul nsw i32 %69, %70, !dbg !19
  call void @llvm.dbg.value(metadata i32 %71, metadata !14, metadata !DIExpression()), !dbg !15
  %73 = icmp eq i32 %71, 0, !dbg !16
  br i1 %73, label %74, label %68, !dbg !18, !llvm.loop !25

74:                                               ; preds = %68, %59, %1
  %75 = phi i32 [ 1, %1 ], [ %63, %59 ], [ %72, %68 ], !dbg !19
  ret i32 %75, !dbg !27
}
